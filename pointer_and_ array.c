/*
이 프로그램은 pointer와 array의 관계를 보여주는 프로그램이다.
포인터의 산술연산에서, 덧셈 연산자는 해당 포인터의 크기만큼 바꾸어 준다.
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
	printf("\n배열 a의 메모리 주소: %0x\n\n", p);
	s = p;
	c = p;

	// 2바이트 jump
	s += 1; ps = s;
	printf("2바이트 건너뛴 ps의 주소: %0x\n", ps);
	printf("2바이트 건너뛴 ps안에 있는 데이터값: %0x\n", *ps); // a55a3cc3
	printf("이를 십진수로 변형: %d\n\n", *ps);

	// 1바이트 jump
	c += 1; pc = c;
	printf("1바이트 건너뛴 pc의 주소: %0x\n", pc);
	printf("1바이트 건너뛴 pc안에 있는 데이터값: %0x\n", *pc); //5a3cc35a
	printf("이를 십진수로 변형: %d\n", *pc);

	return 0;
}