#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 100
float F(float x){return (x - exp(-x));}
//float F(float x){return (pow(x, 5) - 3*x*x*x - 1);}
float cut(float a, float b){return (b - F(b)*(b-a)/(F(b)-F(a)));}

int main(){
	float a, b, m, e;
	int i=1;
	printf("Enter two values: ");
	scanf("%f %f", &a, &b);
	printf("Enter tolerance: ");
	scanf("%f", &e);
	m = cut(a, b);
	printf("%12c%12c%12s%12s%12c%12s\n", 'a', 'b', "F(a)", "F(b)", 'x', "F(x)");
	while(fabs((m-b)/m) > e){
		printf("%12.5f%12.5f%12.5f%12.5f%12.5f%12.5f\n", a, b, F(a), F(b), m, F(m));
		if(F(a) * F(m) > 0) a = m;
		else b = m;
		m = cut(a, b);
		if(i>N){printf("Diverging!\n"); break;}
		++i;
	}

	printf("Solution: %.5f\n", m);	
	return 0;
}