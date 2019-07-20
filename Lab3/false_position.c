#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float F(float x) {return (exp(2.8*x) + cos(x) - 3*x*x);}

float cut(float a, float b){
    return (a - F(a)*(b-a)/(F(b)-F(a)));
}

int main(){
    float a, b, x, f_a, f_b, f_x, tol;

    do{
        a=b=0.0;
        printf("Enter range: ");
        scanf("%f %f", &a, &b);
        f_a = F(a); f_b = F(b);
    }while(f_a * f_b > 0);
    
    printf("Enter tolerance: ");
    scanf("%f", &tol);

    x = cut(a, b);
    f_x = F(x);

    printf("%12c%12c%12s%12s%12c%12s\n", 'a', 'b', "F(a)", "F(b)", 'x', "F(x)");
    while(fabs(f_x) > tol){
        printf("%12.4f%12.4f%12.4f%12.4f%12.4f%12.4f\n", a, b, f_a, f_b, x, f_x);
        if(f_a * f_x > 0) a = x;
        else b = x;
        x = cut(a, b);
        f_x = F(x);
        f_a = F(a);
        f_b = F(b);
    }
    printf("Solution: %.4f\n", x);
    return 0;
}