#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(x) ((1-pow((1+x), 4))/x - 1)

int main(){;
    double a, b, m, y_a, y_m, y_b, tmp, tol;
    int i=1;

    do{
        a = b = 0.0;
        printf("Enter range: ");
        scanf("%lf %lf", &a, &b);
        y_a = F(a);
        y_b = F(b);
    }while(y_a*y_b >0);

    if(a>b){
        tmp = a;
        a = b;
        b = tmp;
    }
    
    printf("Enter tolerance: ");
    scanf("%lf", &tol);
    
    m = (a+b)/2;
    y_m = F(m);


    printf("%3c%12c%12c%12s%12s%12c%12s\n", 'n', 'a', 'b', "F(a)", "F(b)", 'x', "F(x)");
    while(fabs((a-b)/m) > tol){
            m = (a+b) / 2;
            y_m = F(m);
            printf("%3d.%12.4f%12.4f%12.4f%12.4f%12.4f%12.4f\n", i, a, b, y_a, y_b, m, y_m);
            if(y_b * y_m >= 0){
                b = m;
                y_b = y_m;
            }
            else if(y_a * y_m >=0){
                a = m;
                y_a = y_m;
            }
            ++i;
    }
    
    printf("Approx Solution: %.3lf\n", (a+b)/2);

    return 0;
}