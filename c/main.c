#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define COUNT_TYPE unsigned int

const int total_iterations = 10000;

double area(COUNT_TYPE count){
	return 4*(double) count / (double) total_iterations;
}

int main(){
	const unsigned int numdims = 2;
	double dims[numdims];
	COUNT_TYPE c_circle=0, c_cartioid=0;
	
	for (int i = 0; i < total_iterations; i++){
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
	printf("circle count: %d, cartoid count: %d\n", c_circle, c_cartioid);
	printf("circle area: %lf, cartoid area: %lf\n", 
						area(c_circle), 
						area(c_cartioid));


	return 0;
}
