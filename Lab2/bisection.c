#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define F(x) (x*x + 2*x - 4)
#define PRECISION 0.000001

int main(){;
    double a, b, m, y_a, y_m, y_b;
    
    printf("Enter range: ");
    scanf("%lf %lf", &a, &b);
    
    while(b - a > PRECISION){
            m = (a+b) / 2;
            y_a = F(a);
            y_m = F(m);
            if(y_b * y_m >= 0)
                b = m;
            else if(y_a * y_m >=0)
                a = m;
            printf("New Interval: [%.10lf, %.10lf]\n", a, b);
    }

    printf("Approx Solution: %lf\n", (a+b)/2);
    return 0;
}