//============================================================================
// Name        : Palindrome_Loop.c
// Author      : Minsu Jo
// Created on  : 2016. 5. 24.
// Description : Ansi-style
//============================================================================

/* Loop�� �̿��� �Լ��� �迭�� �̿��Ͽ� ������ �¿� ��Ī�� Ȯ���ϴ� ���α׷� */

#include <stdio.h>
#include <string.h>

int is_palindrome(char str[]); // palindrome �Ǻ� �Լ� prototype

int main()
{
	char str[100]; // ���ڿ��� ���̸� �ִ� 100�� ����

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("Please enter a string (length < 100): ");
	scanf("%s", str);

	if(is_palindrome(str)) // �¿� ��Ī�� ���
	{
		printf("%s is a palindrome.", str);
	}
	else // �¿� ��Ī�� �ƴ� ���
	{
		printf("%s is NOT a palindrome.", str);
	}

	return 0;
}

int is_palindrome(char str[])
{
	int i; // index number ���� ����
	int string_length = strlen(str); // ���ڿ��� ���� ���� ���� �� ����
	int distinction = 0; // palindrome �Ǻ� �ڵ� ���� ���� �� �ʱ�ȭ

	for(i = 0; i <= (string_length / 2); i++)
	{
		if(str[i] != str[string_length - 1 - i]) // �¿� ��Ī�� �ƴ� ��찡 ���� ��
		{
			distinction++; // �Ǻ� �ڵ尪 ��ȭ

			if(distinction >= 1) // �ϳ��� �¿� ��Ī�� �ȵǸ� palindrome�ƴ�
			{
				return 0;
			}
		}
	}

	return (distinction == 0);
}
