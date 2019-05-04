#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(x) (exp(-x) * (3.2*sin(x) - 0.5*cos(x)))
#define PRECISION 0.0001

int main(){;
    double a, b, m, y_a, y_m, y_b;
    int i=1;
    printf("-------------------\n");
    printf("Enter range: ");
    scanf("%lf %lf", &a, &b);

    printf("-------------------\n");
    printf("Iterations: %.2f\n", (log10(b-a) - log10(PRECISION))/log10(2));
    
    printf("------------------------------------------------------------------------\n");
    printf("| n    | %-7c | %-7c | %-7.9s | %-7.9s  | %-7c | %-7.9s    |\n", 'a', 'b', "F(a)", "F(b)", 'x', "F(x)");
    printf("------------------------------------------------------------------------\n");
    while(b - a > PRECISION){
            m = (a+b) / 2;
            y_a = F(a);
            y_b = F(b);
            y_m = F(m);
            printf("| %3d. | %7.5f | %7.5f | %7.5f | %7.5f | %7.5f | %8.5f   |\n", i, a, b, y_a, y_b, m, y_m);
            if(y_b * y_m >= 0)
                b = m;
            else if(y_a * y_m >=0)
                a = m;
            ++i;
    }
    printf("------------------------------------------------------------------------\n");
    
    printf("Approx Solution: %lf\n", (a+b)/2);
    printf("-------------------------------\n");
    return 0;
}