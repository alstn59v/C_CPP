//============================================================================
// Name        : Palindrome_Loop.c
// Author      : Minsu Jo
// Created on  : 2016. 5. 24.
// Description : Ansi-style
//============================================================================

/* Loop를 이용한 함수와 배열을 이용하여 문자의 좌우 대칭을 확인하는 프로그램 */

#include <stdio.h>
#include <string.h>

int is_palindrome(char str[]); // palindrome 판별 함수 prototype

int main()
{
	char str[100]; // 문자열의 길이를 최대 100자 까지

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("Please enter a string (length < 100): ");
	scanf("%s", str);

	if(is_palindrome(str)) // 좌우 대칭일 경우
	{
		printf("%s is a palindrome.", str);
	}
	else // 좌우 대칭이 아닐 경우
	{
		printf("%s is NOT a palindrome.", str);
	}

	return 0;
}

int is_palindrome(char str[])
{
	int i; // index number 변수 선언
	int string_length = strlen(str); // 문자열의 길이 변수 선언 및 정의
	int distinction = 0; // palindrome 판별 코드 변수 선언 및 초기화

	for(i = 0; i <= (string_length / 2); i++)
	{
		if(str[i] != str[string_length - 1 - i]) // 좌우 대칭이 아닌 경우가 있을 때
		{
			distinction++; // 판별 코드값 변화

			if(distinction >= 1) // 하나라도 좌우 대칭이 안되면 palindrome아님
			{
				return 0;
			}
		}
	}

	return (distinction == 0);
}
