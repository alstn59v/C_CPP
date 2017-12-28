//============================================================================
// Name        : Palindrome_Recursive.c
// Author      : Minsu Jo
// Created on  : 2016. 5. 24.
// Description : Ansi-style
//============================================================================

/* ��� �Լ��� �迭�� �̿��Ͽ� ������ �¿� ��Ī�� Ȯ���ϴ� ���α׷� */

#include <stdio.h>
#include <string.h>

int is_palindrome(char str[], int start, int end); // palindrome �Ǻ� �Լ� prototype

int main()
{
	char str[100]; // ���ڿ��� ���̸� �ִ� 100�� ����

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("Please enter a string (length < 100): ");
	scanf("%s", str);

	if(is_palindrome(str, 0, strlen(str) - 1)) // �¿� ��Ī�� ���
	{
		printf("%s is a palindrome.", str);
	}
	else // �¿� ��Ī�� �ƴ� ���
	{
		printf("%s is NOT a palindrome.", str);
	}

	return 0;
}

int is_palindrome(char str[], int start, int end)
{
	if(str[start] == str[end - start]) // �� ��� ���ڰ� ���� ��
	{
		if(start == (end / 2)) // ��� �Լ��� ���� ���� ����
		{
			return 1;
		}

		start++; // �ݺ��� ���Ͽ� index number ����

		return is_palindrome(str, start, strlen(str) - 1);
	}
	else // �� ��� ���ڰ� �ٸ� ��
	{
		return 0;
	}
}

