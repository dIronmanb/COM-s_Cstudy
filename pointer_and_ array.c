/*
�� ���α׷��� pointer�� array�� ���踦 �����ִ� ���α׷��̴�.
�������� ������꿡��, ���� �����ڴ� �ش� �������� ũ�⸸ŭ �ٲپ� �ش�.
*/
#include <stdio.h>

int main(void)
{
	int* p, * ps, * pc;
	short* s;
	char* c;

	int a[3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = 0x3CC3A55A;
	}

	for (int i = 0; i < 3; i++)
	{
		printf("a[%d] : %0x\t%d\n", i, a[i], a[i]);
		// 3cc3a55a
	}


	p = &a[0];
	printf("\n�迭 a�� �޸� �ּ�: %0x\n\n", p);
	s = p;
	c = p;

	// 2����Ʈ jump
	s += 1; ps = s;
	printf("2����Ʈ �ǳʶ� ps�� �ּ�: %0x\n", ps);
	printf("2����Ʈ �ǳʶ� ps�ȿ� �ִ� �����Ͱ�: %0x\n", *ps); // a55a3cc3
	printf("�̸� �������� ����: %d\n\n", *ps);

	// 1����Ʈ jump
	c += 1; pc = c;
	printf("1����Ʈ �ǳʶ� pc�� �ּ�: %0x\n", pc);
	printf("1����Ʈ �ǳʶ� pc�ȿ� �ִ� �����Ͱ�: %0x\n", *pc); //5a3cc35a
	printf("�̸� �������� ����: %d\n", *pc);

	return 0;
}