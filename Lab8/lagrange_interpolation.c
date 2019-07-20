#include <stdio.h>
#include <stdlib.h>

int main(){
    float x[10], y[10], xi, yi = 0;
    int n;

    printf("Enter the number of values: ");
    scanf("%d", n);

    printf("Enter %d values for x: ");
    for(int i =0 ; i<n; i++)
        scanf("%f", &x[i]);

    printf("Enter %d values for y: ");
    for(int i =0 ; i<n; i++)
        scanf("%f", &y[i]);

    printf("Enter the point wjere the value is required: ");
    scanf("%f", &xi);

    return 0;
}