#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592

int main(){
    int theta[] = {10, 20, 30, 40, 50}, k=1;
    float sinT[5], diff[4][4];
    
    for(int i = 0; i < 5; i++){
        sinT[i] = sin(theta[i]*PI/180);
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i==0)
                diff[i][j] = sinT[j+1] - sinT[j];
            else if(j < 5-k)
                diff[i][j] = diff[i-1][j+1] - diff[i-1][j];
            else
                diff[i][j] = 0;
        }
        ++k;
    }

    printf("theta\t\tsin(theta)\t\tdd1\t\tdd2\t\tdd3\t\tdd4\n");
    for(int i = 0; i < 5; i++){
        printf("%d\t\t%.4f\t\t", theta[i], sinT[i]);
        for(int j = 0; j < 4; j++){
            if(i == 4)
                putchar(' ');
            else if(diff[j][i] == 0.0f)
                putchar('\t');
            else
                printf("\t%.4f\t", diff[j][i]);
        }
        putchar('\n');
    }
}