#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 100

//float F(float x){return (x*exp(x) - cos(x));}
//float f(float x){return (exp(x) + x*exp(x) + sin(x));}
//double F(double x){return(3*x - cos(x) - 1);}
//double f(double x){return(3 + sin(x));}
double F(double x){return (x*log(x) - 1.2);}
double f(double x){return(log(x) + 1);}

int main(){
	double a, e, an, an2;
	int i=1;
	printf("Enter initial guess: ");
	scanf("%lf", &a);
	printf("Enter tolerance: ");
	scanf("%lf", &e);
	printf("%12s%12s%12s\n", "an", "an+1", "Serror");
	
	while(F(a)>e){
		an = a;
		a = a - F(a)/f(a);
		printf("%12.5lf%12.5lf%12.5lf\n", an, a, F(a));
		if(i>N){printf("Diverging!\n"); break;}
		++i;
	}

	printf("Root: %.8f", a);
	return 0;
}