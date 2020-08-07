#include <stdio.h>
#include <stdbool.h>

/* #define directives go here */
#define NUM_RANKS (13)
#define NUM_SUITS (4)
#define NUM_CARDS (5)

/* declarations of external variables go here */
int num_in_rank[NUM_RANKS];
int num_in_suit[NUM_SUITS];

bool straight, flush, four, three;
int pairs;

/* prototype */
void classify(char card[5][2]);
int Classify_Num(int card[][2]);


/* main function */
int main(void)
{
	char card[5][2] = 0; //�ϴ� 0���� ��� �ʱ�ȭ, 5�� �̱�(ex)S1 S4 H0 DJ DK
	//Ÿ���� char�� ����: RANK���� 0,J,Q,K�� �����Ƿ�

	for (;;) {
		in_hand(card); //card�μ� �ѱ�� - �̶�, �Լ��� ���� card�� ������ �ٲ�
		classify(card); //in_hand�� ���� ���۵�? �����͸� �з�
		result();
	}
	return 0;
}



/* function definitions */
int Classify_Num(int card[][2])
{
	int temp, cnt = 0;
	for (int i = 0; i < 5; i++) //2���� �迭���� �ټ� ��
	{
		temp = card[i][1];		//temp��� �ӽú��� ������!
		for (int j = 0; j < 5; j++) //2���� �迭���� �ټ� ��
		{
			if (temp == card[j][1]) cnt++; //�� 25�� �ݺ�
		}
	}

	return cnt;

}
void classify(char card[5][2]) // shape: 5 x 2
{
	//1. straight(sort)
	{
		//preparation (RANK -> Character type)
		for (int i = 0; i < 5; i++) {
			switch (card[i][1]) {
			case 'A': card[i][1] = 'a'; break;
			case '2': card[i][1] = 'b'; break;
			case '3': card[i][1] = 'c'; break;
			case '4': card[i][1] = 'd'; break;
			case '5': card[i][1] = 'e'; break;
			case '6': card[i][1] = 'f'; break;
			case '7': card[i][1] = 'g'; break;
			case '8': card[i][1] = 'h'; break;
			case '9': card[i][1] = 'i'; break;
			case '0': card[i][1] = 'j'; break;
			case 'J': card[i][1] = 'k'; break;
			case 'Q': card[i][1] = 'l'; break;
			case 'K': card[i][1] = 'm'; break;
			}
		}

		//sort
		int temp;
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (i >= j) continue;
				if (card[i][1] > card[j][1]) {
					temp = card[j][1];
					card[j][1] = card[i][1];
					card[i][1] = temp;
				}
			}
		}
		//identify whether straight is 
		for (int i = 0; i < 5; i++)
		{
			if((i!= 4) && (card[i][1] + 1 == card[i + 1][1]));
			else if (i == 4) straight = true;
			else {straight = false; break;}
		}
	}
	//2. flush
	{
		/*flush�� ��� 1������ �ִ� �����͸� ������ �з��ϹǷ�,
		  ������ ���� classify�Լ��� ����ϱ⿡�� �������ϴ�.*/
		for (int i = 0; i < 5; i++)
		{
			if ( i!=5  && card[i][0] == card[i + 1][0]); //&&�����ڷ� �տ��� �����̸�, ���� ������ �Ⱥ�
			else if(i==5) flush = true;
			else{flush = false; break;}
		}
	}
	//3. four
	{
		int count;
		count = Classify_Num(card);
		if (count == 17) four = true; //classify�Լ� �̿� - 17�� ������ ��ī��
		else four = false;
	}
	//4. three
	{
		int count;
		count = Classify_Num(card);
		if (count == 11) three = true; //classify�Լ� �̿� - 11�� ������ Ʈ����
		else three = false;
	}
	//5. pair
	{
		int count;
		count = Classify_Num(card);
		if (count == 7) pairs = 1; //classify�Լ� �̿� - 7�� ������ �����
		else if (count == 9) pairs = 2; //classify�Լ� �̿� - 9�� ������ �����
		else pairs = 0; //�����ϱ� 0���
	}
	//straight, flush, three���� ��� ���������̹Ƿ� return�� ���� �ʿ� X
}
