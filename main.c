//sigmoid function
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define NUM 5
//double exp(double x) e의 x제곱을 구함.

void InputArray(double[], int size);
void SigmoidArray(double [], int size);
double SigmoidFunction(double x);
void ShowArray(double[], int size);

int main(void)
{
	double a[NUM];
	InputArray(a, NUM);
	SigmoidArray(a, NUM);
	ShowArray(a, NUM);
	return 0;

}

void InputArray(double a[], int size)
{
	printf("배열에 넣을 값을 지정하시오.\n");
	for (int i = 0; i < size; i++)
	{
		printf("[%d] : ", i);
		scanf("%lf", &a[i]);
	}
	printf("\n");
}
void ShowArray(double a[], int size)
{
	printf("배열 출력\n");
	for (int i = 0; i < size; i++)
	{
		printf("a[%d] : %.6f\n", i, a[i]);
	}
	printf("\n");
}
void SigmoidArray(double a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		a[i] = SigmoidFunction(a[i]);
	}
}
double SigmoidFunction(double x)
{
	return 1 / (1 + exp(-x));
}