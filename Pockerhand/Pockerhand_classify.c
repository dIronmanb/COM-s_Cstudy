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
int classify(char card[][2]);
int Classify_Num(int card[][2]);


/* main function */
int main(void)
{
	for (;;) {
		in_hand();
		classify(card);
		result();
	}
	return 0;
}



/* function definitions */
int Classify_Num(int card[][2])
{
	int temp, cnt = 0;
	for (int i = 0; i < 5; i++)
	{
		temp = card[i][1];
		for (int j = 0; j < 5; j++)
		{
			if (temp == card[j][1]) cnt++;
		}
	}

	return cnt;

}
int classify(char card[][2]) // shape: 5 x 2
{
	/*
	straight: 5 Continuous numbers
	flush	: 5 Same shap
	four	: 4 Same numbers
	three	: 3 Same numbers
	pair	: 2 Same numbers
	}
	*/

	//1. straight(sort)
	
	/*pass*/

	//2. flush
	{
		for (int i = 0; i < 5; i++)
		{
			if (card[i][0] == card[i + 1][0]);
			else
			{
				flush = false;
				break;
			}

			if (i >= 4)
			{
				flush = true;
				break;
			}
		}
	}
	//3. four
	{
		/*
		int cnt = 0, another_cnt = 0, temp;
		temp = card[0][1];

		for (int i = 0; i < 5; i++)
		{
			if (temp == card[i][1]) cnt++;
			else another_cnt++; // fisrt num != other nums
		}
		if (cnt == 4 || another_cnt == 4) four = true;
		else four = false;
		*/
		int count;
		count = Classify_Num(card);
		if (count == 17) four = true;
		else four = false;
	}
	//4. three
	{
		int count;
		count = Classify_Num(card);
		if (count == 11) three = true;
		else three = false;
	}
	//5. pair
	{
		int count;
		count = Classify_Num(card);
		if (count == 7) pairs = 1;
		else if (count == 9) pairs = 2;
		else pairs = 0;
	}

	if (straight == true && flush == true) return 1;	//straight-flush
	else if (straight == false && flush == true) return 2; //flush
	else if (straight == true && flush == false) return 3; // straight
	else if (three == true && pairs == 1) return 4; // full-house
	else if (three == true && pairs == 0) return 5; // triple
	else if (pairs == 2) return 6;	//two pair
	else if (pairs == 1) return 7;	//one pair
	else return 0;

}
