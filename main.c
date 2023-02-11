#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	const unsigned int numdims = 2;
	double dims[numdims];
	double c_circle=0, c_cartioid=0;
	
	for (int i = 0; i < 2000; i++){
		// gen rand coord
		for (unsigned int j = 0; j < numdims; j++){
			dims[j] = 2*(double) rand() / (double) (RAND_MAX) -1;
		}
		//printf("%f\n", x);
		//check if coord is in what is within shape
		c_circle += (pow(dims[0],2) + pow(dims[1],2) < 1)? 1 : 0;
		c_cartioid += (pow(pow(dims[0],2) + pow(dims[1],2), 2) + dims[0] * (pow(dims[0],2) + pow(dims[1], 2)) - 0.25*pow(dims[1], 2) < 0) ? 1: 0;
		//printf("%lf\t %lf\n", x,y);
		printf("%.30lf\n", c_cartioid/c_circle);
	}

	return 0;
}
