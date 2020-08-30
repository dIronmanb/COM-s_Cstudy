// 테일러급수를 활용하여 exp(x) 만들기


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

double Exp_function(int n, int x);
double Factorial(int n);
int Pow(int, int);

int main(void)
{
	int iter, exponent;
	printf("This program prints exponential approximation\n");
	printf("Enter the number of iteration: ");			scanf("%d", &iter);
	printf("Enter the number of exponential part: ");	scanf("%d", &exponent);

	//Using Exponential Function
	printf("exp(%d) is %.8f (%d iters)\n\n", exponent, Exp_function(iter, exponent), iter);

	printf("Using  <math.h> library: %.8f\n", exp(exponent));
	printf("Using  my  own  library: %.8f\n", Exp_function(iter, exponent));



	return 0;
}


double Exp_function(int n, int x)
{
	double series = 0;
	series += 1; // -> a/0!

	for (int i = 1; i <= n; i++)
	{
		series += (Pow(x, i) / Factorial(i));
	}

	return series;
}


//팩토리얼
double Factorial(int n)
{
	double phi = 1;
	if (n == 0) return phi;		//0! = 1
	else if (n == 1) return phi;//1! = 1

	for (int i = 1; i <= n; i++)
	{
		phi *= i;
	}

	return phi;
}
//제곱
int Pow(int x, int exponent)
{
	int pow = 1;
	for (int i = 0; i < exponent; i++)
	{
		pow *= x;
	}
	return pow;
}