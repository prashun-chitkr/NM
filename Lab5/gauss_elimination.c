#include <stdio.h>
#include <stdlib.h>

int main(){
    float arr[10][10], x[10], c;
    int i, j, k, n;
    printf("Enter number of equations: ");
    scanf("%d", &n);
    printf("Enter the augumented matrix:\n");
    for(i=0; i<n; i++)
        for(j=0; j<n+1; j++)
            scanf("%f", &arr[i][j]);

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(i>j){
                c = arr[i][j]/arr[j][j];
                for(k=0; k<n+1; k++){
                    arr[i][k] = arr[i][k] - c*arr[j][k];
                }
            }
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<n+1; j++)
            printf("%6.2f ", arr[i][j]);
        putchar('\n');
    }
    return 0;
}