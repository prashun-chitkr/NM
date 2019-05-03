#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    float xy[5][5] = {{0.0, 1.0 ,2.0 , 3.0, 0.0}, {1.05, 2.10, 3.85, 8.30, 0.0}};
    int i, j;


    xy[0][4] = 0;

    for(i=0; i<4; i++){
		xy[2][i] = log(xy[1][i]);
		xy[3][i] = xy[0][i] * xy[0][i];
		xy[4][i] = xy[0][i] * xy[2][i];
		xy[0][4] += xy[0][i];
		xy[1][4] += xy[1][i];
		xy[2][4] += xy[2][i];
		xy[3][4] += xy[3][i];
		xy[4][4] += xy[4][i];
    }
    
    printf("x\ty\tln(y)\tx*x\tx*ln(y)\n");
    for(i = 0; i < 5; i++){
		for(j = 0; j < 5; j++)
		    printf("%.4f\t", xy[j][i]);
		putchar('\n');
    }

    return 0;
}