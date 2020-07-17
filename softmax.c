//softmax function - ��� �迭 ������ ���� 1�̴�.(Ȯ���� ���� ����)
//��, ���ҿ� ���� ���� �ʹ� ũ�� �ϸ� overflow�ǰų� �̻��� ���� ���´�.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define NUM 5

void InputArray(double[], int size);
void ShowArray(double[], int size);
void SoftmaxArray(double[], int size);
double SoftmaxFunction(double x, double sum_exp);
double Maxnum(double a[], int size);
double ExpSumArray(double a[], int size, double max);
double SumArray(double a[], int size);

int main(void)
{
	double a[NUM];
	InputArray(a, NUM);
	SoftmaxArray(a, NUM);
	ShowArray(a, NUM);

	printf("%f\n", SumArray(a, NUM));

	return 0;
}

void InputArray(double a[], int size)
{
	printf("�迭�� ���� ���� �����Ͻÿ�.\n");
	for (int i = 0; i < size; i++)
	{
		printf("[%d] : ", i);
		scanf("%lf", &a[i]);
	}
	printf("\n");
}
void ShowArray(double a[], int size)
{
	printf("�迭 ���\n");
	for (int i = 0; i < size; i++)
	{
		printf("a[%d] : %.6f\n", i, a[i]);
	}
	printf("\n");
}
void SoftmaxArray(double a[], int size)
{
	double max, sum_exp;
	max = Maxnum(a, NUM);
	sum_exp = ExpSumArray(a, NUM, max);
	for (int i = 0; i < size; i++)
	{
		a[i] = SoftmaxFunction(a[i]-max, sum_exp);
	}
}
double SoftmaxFunction(double x, double sum_exp)
{
	return exp(x) / sum_exp;
}
double Maxnum(double a[], int size)
{
	double max = a[0];
	for (int i = 0; i < size; i++)
	{
		if (max >= a[i]) continue;
		else max = a[i];
	}
	return max;
}
double ExpSumArray(double a[], int size, double max)
{
	double _exp_[NUM] = { 0 } ;
	double sum= 0;
	for (int i = 0; i < size; i++)
	{
		_exp_[i] = a[i] - max;
		_exp_[i] = exp(_exp_[i]);
		sum += _exp_[i];
	}
	return sum;
}
double SumArray(double a[], int size)
{
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += a[i];
	}
	return sum;
}