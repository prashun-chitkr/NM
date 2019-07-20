#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float geta(float x, float y, float b, int n){
    return (y-b*x)/n;
}

float getb(float x, float y, float xy, float x2, int n){
    return (n*xy - x*y)/(n*x2 - x*x);
}

void linearFit(float x[], float y[], int n){
    float sumx, sumy, sumxy, sumx2, a, b;
    sumx=sumy=sumxy=sumx2=0.0;
    for(int i=0; i<n; i++){
        sumx+=x[i];
        sumy+=y[i];
        sumxy+=x[i]*y[i];
        sumx2+=x[i]*x[i];
    }
    b = getb(sumx, sumy, sumxy, sumx2, n);
    a = geta(sumx, sumy, b, n);
    printf("Required equation is:\ny = %f + %fx\n", a, b);
}

void expFit(float x[], float y[], int n){
    float sumx, sumy, sumxy, sumx2, a, b;
    sumx=sumy=sumxy=sumx2=0.0;
    for(int i=0; i<n; i++){
        sumx+=x[i];
        sumy+=log(y[i]);
        sumxy+=x[i]*log(y[i]);
        sumx2+=x[i]*x[i];
    }
    b = exp(getb(sumx, sumy, sumxy, sumx2, n));
    a = exp(geta(sumx, sumy, b, n));
    printf("Required equation is:\ny = %fe^(%fx)\n", a, b);
}

void saturationFit(float x[], float y[], int n){
     float sumx, sumy, sumxy, sumx2, a, b;
    sumx=sumy=sumxy=sumx2=0.0;
    for(int i=0; i<n; i++){
        sumx+=1/x[i];
        sumy+=1/y[i];
        sumxy+=1/x[i]*1/y[i];
        sumx2+=1/x[i]*1/x[i];
    }
    b = getb(sumx, sumy, sumxy, sumx2, n);
    a = geta(sumx, sumy, b, n);
    b/=a;
    a=1/a;
    printf("Required equation is:\ny = %f/(%f + x)\n", a, b);
}

int main(){
    float *x, *y;
    int n;
    printf("Enter the number of data: ");
    scanf("%d", &n);
    x = (float*)malloc(n*sizeof(float));
    y = (float*)malloc(n*sizeof(float));

    printf("Enter the values of x and y:\n");
    for(int i=0; i<n; i++){
        scanf("%f %f", &x[i], &y[i]);
    }

    linearFit(x, y, n);
    expFit(x, y, n);
    saturationFit(x, y, n);
    return 0;
}