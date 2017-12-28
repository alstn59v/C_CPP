//============================================================================
// Name        : Prime_Counter.c
// Author      : Minsu Jo
// Created on  : 2016. 5. 24.
// Description : Ansi-style
//============================================================================

/* �Լ��� �̿��� 2���� n���� �Ҽ��� ���� ���ϱ� */

#include <stdio.h>
#include <math.h>

int is_prime(int n); // �Ҽ� �Ǻ� �Լ� prototype
int prime_count(int n); // �Ҽ��� ������ ���ϴ� �Լ� prototype

int main()
{
	int n; // �Է¹��� ���� ����

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("Please enter an integer number (>=2): ");
	scanf("%d", &n);

	printf("The number of prime numbers between 2 and %d is %d", n, prime_count(n));

	return 0;
}

int is_prime(int n) // �Ҽ� �Ǻ� �Լ�
{
	int number_aliquot = 0; // ����� ���� ���� ���� �� �ʱ�ȭ
	int divisor; // ���� �� ���� ����

	for(divisor = 1; divisor <= floor(sqrt(n)); divisor++)
	{ // �Ҽ��� sqrt(n)���� �������� ����� 1�ۿ� ������ ����
		if(n % divisor == 0) // n�� ���������� ���
		{
			number_aliquot++; // ����� ���� 1����

			if(number_aliquot >= 2) // 1���� sqrt(n)���̿� ����� ������ 2�� ���ʹ� �Ҽ��� �ƴ�
			{
				return 0; // ���� �ߴ� -> ���� �ӵ��� ������
			}
		}
	}

	return (number_aliquot == 1); // true(�Ҽ��� ���)�̸� 1, false(�Ҽ��� �ƴ� ���)�̸� 0�� ��ȯ
}

int prime_count(int n) // �Ҽ��� ������ ���ϴ� �Լ�
{
	static int number_prime = 0; // �Ҽ��� ���� ���� ���� �� �ʱ�ȭ
	int i; // index number ���� ����

	for(i = 2; i <= n; i++) // �Ҽ��� 2���� �����ϰ� n���� �Ǻ��ؾ� ��
	{
		if(is_prime(i) == 1) // �Ҽ��� ���
		{
			number_prime++; // �Ҽ��� ���� 1����
		}
	}

	return number_prime; // �Ҽ��� ���� ��ȯ
}
