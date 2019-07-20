#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(float x){
    return x/(1+sin(x));
}

void trapezoidal(float low, float high, float step, int n){
    float area = f(low)+f(high);

    for(int i=0; i<n; i++)
        area += 2*f(low+step*i);
    area *= step/2;
    printf("Area from trapeziodal rule: %f\n", area);
}

void simpson1(float low, float high, float step, int n){
    float area = f(low)+f(high);
    for(int i=0; i<n; i++){
        if(!(i%2))
            area += 2*f(low+i*step);
        else
            area += 4*f(low+i*step);
    }
    printf("Area from simpson's 1/3rd rule = %f\n", area*1/3*step);
}

void simpson2(float low, float high, float step, int n){
    float area = f(low)+f(high);

    for(int i=0; i<n; i++){
        if(!(i%3))
            area += 2*f(low+i*step);
        else
            area += 3*f(low+i*step);
    }

    printf("Area from simpson's 3/8th rule = %f\n", area*3/8*step);
}

int main(){
    float low, high, step;
    int n;
    
    printf("Enter low, high and number of data: ");
    scanf("%f %f %d", &low, &high, &n);

    step = (high-low)/n;

    trapezoidal(low, high, step, n);
    simpson1(low, high, step, n);
    simpson2(low, high, step, n);

    return 0;
}