#include <stdio.h>
#include <math.h>

int main(){
    int x[] = {2, 4, 6, 8, 10, 12}, i, j, k=0;
    float y[6][6] = {{5.1, 4.2, 3.1, 3.5, 6.2, 7.3}};
    for(i=1; i<6; i++){
        for(j=0; j<6-k; j++){
            y[i][j] = y[i-1][j+1] - y[i-1][j];
        }
        ++k;
    }
    k=0;
    printf("x\ty\tIFD\tIIFD\tIIIFD\tIVFD\tVFD\n");
    for(i=0; i<6; i++){
        printf("%d\t", x[i]);
        for(j=0; j<6-k; j++){
            printf("%.3f\t", y[j][i]);
        }
        printf("\n");
        ++k;
    }
    return 0;
}