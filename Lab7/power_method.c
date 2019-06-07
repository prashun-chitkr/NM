#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

void init(float *mat, float *v1, float *v2, int n){
    for(int i=0; i<n; i++)
        mat[i] = 0.0;
    *v1 = 0.0;
    *v2 = 0;
}

float max(float mat[10], int n){
    float max = mat[0];
    for(int i=1; i<n; i++)
        if(mat[i] > max)
            max = mat[i];
    return max;
}

bool compare(float mat[10], float mat_old[10], float val, float val_old, float e, int n){
    bool matrix = abs(mat_old[0] - mat[0]) < e;
    bool value = fabs(val_old-val) < e;
    for(int i=0; i<n; i++){
        matrix = (fabs(mat_old[i] - mat[i]) < e) && matrix;

    }
    return matrix && value;
}

int main(){
    float coeff[10][10], guess[10], vector[10], elgen_val, elg_val_old, tol;
    int n;
    
    printf("Enter the dimention of square matrix: ");
    scanf("%d", &n);

    init(vector, &elgen_val, &elg_val_old, n);

    printf("Enter the values of square matrix:\n");
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            scanf("%f", &coeff[i][j]);

    printf("Enter the initial guess matrix of order 1x%d:\n", n);
    for(int i=0; i<n; i++)
        scanf("%f", &guess[i]);

    printf("Enter tolerance: \n");
    scanf("%f", &tol);

    while(!compare(vector, guess, elgen_val, elg_val_old, tol, n)){
        for(int i=0; i<n; i++){
            vector[i] = 0;
            for(int j=0; j<n; j++)
                vector[i] +=coeff[i][j]*guess[j];
        }
        elg_val_old = elgen_val;
        elgen_val = max(vector, n);
        for(int j = 0; j<n; j++){
            vector[j] /= elgen_val;
            guess[j] = vector[j];
        }
    }

    printf("\n\n*****Elgen Value: %.2f*****\n\n", elgen_val);
    printf("Elgen vector:\n");
    for(int i=0; i<n; i++)
        printf("%5.2f\n", vector[i]);
    return 0;
}