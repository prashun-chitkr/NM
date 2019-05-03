#include <stdio.h>
#include <math.h>

int main(){
	float x[7], f_x[7][7]= {{0.193, 0.195, 0.198, 0.201, 0.203, 0.206, 0.208}};
	int i, j, k=0;

	// Loading Data into x //
	x[0] = 7.47;
	for(i=1; i<7; i++)
		x[i] = x[i-1] + 0.01;

	// Calculation //
	for(i=1; i<7; i++){
		for(j=0; j<7-k; j++)
			f_x[i][j] = f_x[i-1][j+1] - f_x[i-1][j];
		++k;
	}

	// Printing //
	printf("x\tf(x)\tD1\tD2\tD3\tD4\tD5\tD6\n");
	for(i=0; i<7; i++){
		k=i;
		printf("%.2f\t", x[i]);
		for(j=0; j<=i; j++){
				printf("%.3f\t", f_x[j][k]);
				--k;
		}
		printf("\n");
	}
	return 0;
}