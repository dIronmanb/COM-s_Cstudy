#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_INPUT 256

void InputString(char input[]);
void PreprocessString(char input[], char processed[]);
void IsPalindrome(char processed[]);

int main(void)
{
	char input[MAX_INPUT] = { 0 };
	char process[MAX_INPUT] = { 0 };

	InputString(input);
	PreprocessString(input, process);
	IsPalindrome(process);

	return 0;
}

void InputString(char input[])
{
	printf("Enter the arbitrary string: ");
	fgets(input, MAX_INPUT, stdin);
	input[strlen(input) - 1] = '\0'; // \n\0 >> \0\0
}

void PreprocessString(char input[], char processed[])
{
	char* cptr = &input[0];
	int cnt = 0, len = strlen(input);

	for (int i = 0; i < len; i++, cptr++) {

		if (*cptr >= 'A' && *cptr <= 'Z') {
			processed[cnt] = *cptr;
			cnt++;
		}
		else if (*cptr >= 'a' && *cptr <= 'z') {
			processed[cnt] = *cptr - ('a' - 'A');
			cnt++;
		}
		if (input[i] == '\0') break;
	}
}

void IsPalindrome(char c[])
{
	//짝수: 나누기 - 그대로 진행
	//홀수: 나누기(x) - (strlen - 1)/2
	bool is_palindrome = true;
	int distance = strlen(c);
	char* for_ptr = &c[0], * back_ptr = &c[distance - 1];


	if (distance % 2 == 1) distance = (distance - 1) / 2;
	else distance /= 2;

	for (int i = 0; i < distance; i++) {

		if (*for_ptr++ == *back_ptr--) continue;
		else
		{
			is_palindrome = false;
			break;
		}

	}

	if (is_palindrome) printf("Palindrome\n");
	else printf("Not Palindrome\n");
}