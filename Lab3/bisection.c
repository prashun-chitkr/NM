#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(x) (x*x*x + x*x + x + 7)
#define PRECISION 0.0001

int main(){;
    double a, b, m, y_a, y_m, y_b, tmp;
    int i=1, iterations;

    printf("-------------------\n");

    do{
        a = b = 0.0;
        printf("Enter range: ");
        scanf("%lf %lf", &a, &b);
    }while((F(a)*F(b))>0);

    if(a>b){
        tmp = a;
        a = b;
        b = tmp;
    }
    
    printf("-------------------\n");

    iterations = (int)(log10(b-a) - log10(PRECISION))/log10(2) + 1;
    printf("Iterations: %d\n", iterations);
    
    printf("------------------------------------------------------------------------\n");

    printf("| n    | %-7c | %-7c | %-7.9s | %-7.9s  | %-7c | %-7.9s    |\n", 'a', 'b', "F(a)", "F(b)", 'x', "F(x)");

    printf("------------------------------------------------------------------------\n");

    while(i <= iterations){
            m = (a+b) / 2;
            y_a = F(a);
            y_b = F(b);
            y_m = F(m);
            printf("| %3d. | %7.4f | %7.4f | %7.4f | %7.4f | %7.4f | %8.4f   |\n", i, a, b, y_a, y_b, m, y_m);
            if(y_b * y_m >= 0)
                b = m;
            else if(y_a * y_m >=0)
                a = m;
            ++i;
    }
    printf("------------------------------------------------------------------------\n");
    
    printf("Approx Solution: %4.3lf\n", (a+b)/2);

    printf("-------------------------------\n");
    return 0;
}