// 테일러급수를 활용하여 삼각함수 sin(x), cos(x) 만들기


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

void Load_Sin(void);
void Load_Cos(void);

double sin_function(int x, int iter);
double cos_function(int x, int iter);

double Factorial(int n);
int Pow(int, int);

int main(void)
{
	int choice;
	printf("1:sin_function, 2:cos_function, 0:Exit");
	do
	{
		printf("\nPress number: ");
		scanf("%d", &choice);

		if (choice == 1) Load_Sin();
		else if (choice == 2) Load_Cos();


	} while (choice != 0);

	return 0;
}

void Load_Sin(void)
{
	int iter, val;
	printf("\nThis program prints sin approximation\n");
	printf("Enter the number of iteration: ");			scanf("%d", &iter);
	printf("Enter the number of value in sin: ");	scanf("%d", &val);

	//Using sin
	printf("sin(%d) is %.8f (%d iters)\n", val, sin_function(val, iter), iter);
	printf("Using  <math.h> library: %.8f\n", sin(val));
	printf("Using  my sin  function: %.8f\n", sin_function(val, iter));
}

void Load_Cos(void)
{
	int iter, val;
	printf("\nThis program prints cos approximation\n");
	printf("Enter the number of iteration: ");			scanf("%d", &iter);
	printf("Enter the number of value in cos: ");	scanf("%d", &val);

	//Using sin
	printf("cos(%d) is %.8f (%d iters)\n", val, cos_function(val, iter), iter);
	printf("Using  <math.h> library: %.8f\n", cos(val));
	printf("Using  my cos  function: %.8f\n", cos_function(val, iter));
}


double sin_function(int x, int n)
{
	double series = 0;
	//n은 반복 수, 2n+1은 넣을 수

	for (int i = 0; i <= n; i++)
	{
		series += (Pow(-1, i) * (Pow(x, 2 * i + 1) / Factorial(2 * i + 1)));
	}

	return series;
}

double cos_function(int x, int n)
{
	double series = 0;
	//n은 반복 수, 2n+1은 넣을 수

	for (int i = 0; i <= n; i++)
	{
		series += (Pow(-1, i) * (Pow(x, 2 * i) / Factorial(2 * i)));
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
	if (exponent == 0) return 1;
	int pow = 1;
	for (int i = 0; i < exponent; i++)
	{
		pow *= x;
	}
	return pow;
}