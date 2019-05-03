#include <stdio.h>
#include <math.h>
#define F(a) (pow(a, 3) - 4*a -9)
#define G(b) (3*b*b - 4)

int main(){
    float a = 0.0, b=0.0;
    printf("a\tb\tF(a)\t\tG(b)\n");
    while(b!=5.0){
        printf("%.2f\t%.2f\t%f\t%f\n", a, b, F(a), G(b));
        a+=0.25;
        b+=0.5;
    }
    return 0;
}
