#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592

int main(){
    int theta[] = {10, 20, 30, 40, 50}, i, j;
    float sinT[5], diff[4][4];


    for(i = 0; i < 5; i++)
        sinT[i] = sin(theta[i]*PI/180);

    for(i = 0; i < 4; i++){
        for(j = 0; j < 5-i; j++){
            if(i==0)
                diff[i][j] = sinT[j+1] - sinT[j];
            else
                diff[i][j] = diff[i-1][j+1] - diff[i-1][j];
        }
    }

    printf("theta\tsin(theta)\tID\t\tIID\t\tIIID\t\tIVD\n");
    for(i = 0; i < 5; i++){
        printf("%d\t%.4f\t\t", theta[i], sinT[i]);
        for(j=0; j<4-i; j++)
            printf("%.4f\t\t", diff[j][i]);
        putchar('\n');
    }

    return 0;
}