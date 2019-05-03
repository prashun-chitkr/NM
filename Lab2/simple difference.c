#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592

int main(){
    int theta[] = {10, 20, 30, 40, 50}, i, j, k=1;
    float sinT[5], diff[4][4];


    for(i = 0; i < 5; i++)
		sinT[i] = sin(theta[i]*PI/180);

    for(i = 0; i < 4; i++){
		for(j = 0; j < 4; j++){
		    if(i==0)
				diff[i][j] = sinT[j+1] - sinT[j];
		    else if(j < 5-k)
				diff[i][j] = diff[i-1][j+1] - diff[i-1][j];
		    else
				diff[i][j] = 0;
		}
		++k;
    }

    printf("theta\tsin(theta)\tdd1\t\tdd2\t\tdd3\t\tdd4\n");
    for(i = 0; i < 10; i++){
			if(i%2 == 0){
					printf("%d\t%.4f\t\t", theta[i/2], sinT[i/2]);
					for(j = 0; j < 4; j++){
						if((i==2||i==4||i==6) && j==1)
								printf("\t\t%.4f\t", diff[1][i/2-1]);
						if(i==4 && j==3)
								printf("\t\t\t%.4f", diff[3][0]);
					}
			}
			else{
					printf("\t\t\t");
					for(j = 0; j < 4; j++){
                        if((i==1||i==3||i==5||i==7) && j==0)
                                printf("%.4f\t", diff[0][i/2]);
                        if((i==3||i==5) && j==2)
                                printf("\t\t\t%.4f", diff[2][i/2-1]);
					}
			}
			putchar('\n');
    }

    return 0;
}