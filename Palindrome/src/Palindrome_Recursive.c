//============================================================================
// Name        : Palindrome_Recursive.c
// Author      : Minsu Jo
// Created on  : 2016. 5. 24.
// Description : Ansi-style
//============================================================================

/* 재귀 함수와 배열을 이용하여 문자의 좌우 대칭을 확인하는 프로그램 */

#include <stdio.h>
#include <string.h>

int is_palindrome(char str[], int start, int end); // palindrome 판별 함수 prototype

int main()
{
	char str[100]; // 문자열의 길이를 최대 100자 까지

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("Please enter a string (length < 100): ");
	scanf("%s", str);

	if(is_palindrome(str, 0, strlen(str) - 1)) // 좌우 대칭일 경우
	{
		printf("%s is a palindrome.", str);
	}
	else // 좌우 대칭이 아닐 경우
	{
		printf("%s is NOT a palindrome.", str);
	}

	return 0;
}

int is_palindrome(char str[], int start, int end)
{
	if(str[start] == str[end - start]) // 비교 대상 문자가 같을 때
	{
		if(start == (end / 2)) // 재귀 함수의 종료 조건 지정
		{
			return 1;
		}

		start++; // 반복을 위하여 index number 증가

		return is_palindrome(str, start, strlen(str) - 1);
	}
	else // 비교 대상 문자가 다를 때
	{
		return 0;
	}
}

