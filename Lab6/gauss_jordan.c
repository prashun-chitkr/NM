#include <stdio.h>
#include <stdlib.h>

void display(float arr[10][10], int n){
    putchar('\n');
    for(int i=0; i<n; i++){
        for(int j=0; j<n+1; j++)
            printf("%10f ", arr[i][j]);
        putchar('\n');
    }
}

int main(){
    float coeff[10][10], temp;
    int i, j, k, n;

    printf("Enter the number of equiation: ");
    scanf("%d", &n);

    /* Asking augumented matrix */
    printf("Enter the coeffencients:\n");
    for(i=0; i<n; i++)
        for(j=0; j<n+1; j++)
            scanf("%f", &coeff[i][j]);
    printf("Entered matrix is:");
    display(coeff, n);
    
    /* Elimination */
    for(i=0; i<n; i++){
        temp = coeff[i][i];
        printf("\nOperating R%d->R%d/%f\n", i+1, i+1, temp);
        for(j=0; j<n+1; j++)
            coeff[i][j] /= temp;
        
        display(coeff, n);
        
        for(j=0; j<n; j++){
            if(i==j)
                continue;
            temp = coeff[j][i];
            printf("\nOperating R%d->R%d-(%f)*R%d\n", j+1, j+1, temp, i+1);
            for(k=0; k<n+1; k++)
                coeff[j][k] -= temp*coeff[i][k];            
        }
        display(coeff, n);
    }

    printf("The roots are:\n");
    for(i=0; i<n; i++){
        printf("x%d: %f\n", i+1, coeff[i][n]);
    }
    return 0;
}