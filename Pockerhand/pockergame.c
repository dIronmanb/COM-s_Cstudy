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
	char card[5][2] = 0; //일단 0으로 모두 초기화, 5장 뽑기(ex)S1 S4 H0 DJ DK
	//타입이 char인 이유: RANK에는 0,J,Q,K가 있으므로

	for (;;) {
		in_hand(card); //card인수 넘기기 - 이때, 함수를 통해 card속 데이터 바뀜
		classify(card); //in_hand를 통해 조작된? 데이터를 분류
		result();
	}
	return 0;
}



/* function definitions */
int Classify_Num(int card[][2])
{
	int temp, cnt = 0;
	for (int i = 0; i < 5; i++) //2차원 배열에서 다섯 번
	{
		temp = card[i][1];		//temp라는 임시변수 설정함!
		for (int j = 0; j < 5; j++) //2차원 배열에서 다섯 번
		{
			if (temp == card[j][1]) cnt++; //총 25번 반복
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
		/*flush의 경우 1차원에 있는 데이터를 가지고 분류하므로,
		  위에서 만든 classify함수를 사용하기에는 부적절하다.*/
		for (int i = 0; i < 5; i++)
		{
			if ( i!=5  && card[i][0] == card[i + 1][0]); //&&연산자로 앞에도 거짓이면, 뒤의 내용은 안봄
			else if(i==5) flush = true;
			else{flush = false; break;}
		}
	}
	//3. four
	{
		int count;
		count = Classify_Num(card);
		if (count == 17) four = true; //classify함수 이용 - 17번 같으면 포카드
		else four = false;
	}
	//4. three
	{
		int count;
		count = Classify_Num(card);
		if (count == 11) three = true; //classify함수 이용 - 11번 같으면 트리플
		else three = false;
	}
	//5. pair
	{
		int count;
		count = Classify_Num(card);
		if (count == 7) pairs = 1; //classify함수 이용 - 7번 같으면 원페어
		else if (count == 9) pairs = 2; //classify함수 이용 - 9번 같으면 투페어
		else pairs = 0; //없으니까 0페어
	}
	//straight, flush, three등이 모두 전역변수이므로 return값 굳이 필요 X
}
