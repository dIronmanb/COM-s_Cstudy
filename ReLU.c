//ReLU function
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NUM 4

void InputArray(double[], int size);
void ShowArray(double[], int size);
void ReLUArray(double[], int size);
double ReLUFunction(double x);

int main(void)
{
	double a[NUM];
	InputArray(a, NUM);
	ReLUArray(a, NUM);
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
void ReLUArray(double a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		a[i] = ReLUFunction(a[i]);
	}
}
double ReLUFunction(double x)
{
	if (x > 0) return x;
	else return 0;
}