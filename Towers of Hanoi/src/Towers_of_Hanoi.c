//============================================================================
// Name        : Towers_of_Hanoi.c
// Author      : Minsu Jo
// Created on  : 2016. 6. 11.
// Description : Ansi-style
//============================================================================

/* ����Լ��� �̿��� �ϳ����� ž �̵� Ƚ�� ���ϱ� */

#include <stdio.h>

void hanoiTower(int n, char from, char temp, char to); // �̵� Ƚ�� ��� �Լ�
int count; // �̵� Ƚ��

int main()
{
	int n; // �̵���ų ������ ����

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("Please enter the number of disc : ");
	scanf("%d", &n);

	hanoiTower(n, 'A', 'B', 'C'); // �̵� Ƚ�� ��� �Լ��� n�� �־ ȣ��

	printf("Move : %d times.", count);

	return 0;
}

void hanoiTower(int n, char from, char temp, char to)
{ // �ϳ����� ž ��ȭ�� => A(n) = 2(A(n-1)) + 1
	if(n == 1) // ������ �ϳ��� ���
	{
		printf("Move  [disc %d]  from <%c>  to  <%c>.\n", n, from, to);
		count++;
	}
	else // ������ �ϳ��� �ƴ� ���
	{
		hanoiTower(n-1, from, to, temp);
		printf("Move  [disc %d]  from <%c>  to  <%c>.\n", n, from, to);
		count++;
		hanoiTower(n-1, temp, from, to);
	}
}
