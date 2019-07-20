#include <stdio.h>
#include <stdlib.h>

int main(){
    float x[10], y[10], a, s, t, k=0;
    int n;

    printf("Enter the number of values: ");
    scanf("%d", n);

    printf("Enter %d values for x and y: ");
    for(int i =0 ; i<n; i++)
        scanf("%f %f", &x[i], &y[i]);

    printf("Enter the point where the value is required: ");
    scanf("%f", &a);

    for(int i=0; i<n; i++){
        s=t=1.0;
        for(int j=0; j<n; j++){
            if(j!=i){
                s = s*(a-x[j]);
                t = t*(x[i]-x[j]);
            }
        }
        k += (s/t)*y[i];
    }

    printf("The required value is: %f\n", t);
    return 0;
}