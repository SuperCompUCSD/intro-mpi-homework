#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <mpi.h>

#define COUNT_TYPE unsigned int

COUNT_TYPE itter_count,
		   total_iterations = 100000000; 

int numtasks,
	taskid;

const unsigned int numdims = 2;

COUNT_TYPE calculate_iterations(const COUNT_TYPE *total_iterations, const int *taskid, const int *numtasks){
	return *total_iterations / *numtasks + ((int) (*total_iterations % *numtasks) > *taskid);
}

double area(COUNT_TYPE count){
	return 4*(double)count / (double)total_iterations;
}


int main(int argc, char *argv[]){
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &taskid);
	MPI_Comm_size(MPI_COMM_WORLD, &numtasks);
	COUNT_TYPE itter_count = calculate_iterations( &total_iterations, &taskid, &numtasks);

	// seed
	srand(1+taskid);
	//printf("%02d, %d : ", taskid, calculate_iterations(&total_iterations, &taskid, &numtasks));


	double dims[numdims];
	COUNT_TYPE c_circle=0, c_cartioid=0;
	
	for (COUNT_TYPE i = 0; i < itter_count; i++){
		// gen rand coord
		for (unsigned int j = 0; j < numdims; j++){
			dims[j] = 2*(double) rand() / (double) (RAND_MAX) -1;
		}
		//printf("%f\n", x);
		//check if coord is in what is within shape
		c_circle += (pow(dims[0],2) + pow(dims[1],2) < 1)? 1 : 0;
		c_cartioid += (pow(pow(dims[0],2) + pow(dims[1],2), 2) + dims[0] * (pow(dims[0],2) + pow(dims[1], 2)) - 0.25*pow(dims[1], 2) < 0) ? 1: 0;
		//printf("%lf\t %lf\n", x,y);
		//printf("%.30lf\n", c_cartioid/c_circle);
	}

	//printf("%02d, %d, %d\n", taskid, c_circle, c_cartioid);

	COUNT_TYPE counts[] = {c_circle, c_cartioid};
	COUNT_TYPE *total_arr = NULL;
	if (taskid == 0){
		total_arr = malloc(sizeof(unsigned int)*numtasks*2);
	}
	MPI_Gather( &counts, 2, MPI_UNSIGNED, total_arr, 2, MPI_UNSIGNED, 0, MPI_COMM_WORLD);
	
	if (taskid == 0){
		COUNT_TYPE total[] = {0,0};
		for (int i = 0; i < numtasks; i++){
			//printf("%d, %d %d\n", i, total_arr[i*2], total_arr[i*2+1]);
			total[0] += total_arr[i*2];
			total[1] += total_arr[i*2+1];
		}
		printf("circle count: %d cartiod count: %d\n", total[0], total[1]);
		printf("circle area: %lf cartiod area: %lf\n", 
				area(total[0]), 
				area(total[1]));
	}

	MPI_Finalize();
	return 0;
}
