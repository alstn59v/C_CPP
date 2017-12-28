//============================================================================
// Name        : Towers_of_Hanoi.c
// Author      : Minsu Jo
// Created on  : 2016. 6. 11.
// Description : Ansi-style
//============================================================================

/* 재귀함수를 이용한 하노이의 탑 이동 횟수 구하기 */

#include <stdio.h>

void hanoiTower(int n, char from, char temp, char to); // 이동 횟수 계산 함수
int count; // 이동 횟수

int main()
{
	int n; // 이동시킬 원판의 개수

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("Please enter the number of disc : ");
	scanf("%d", &n);

	hanoiTower(n, 'A', 'B', 'C'); // 이동 횟수 계산 함수에 n을 넣어서 호출

	printf("Move : %d times.", count);

	return 0;
}

void hanoiTower(int n, char from, char temp, char to)
{ // 하노이의 탑 점화식 => A(n) = 2(A(n-1)) + 1
	if(n == 1) // 원판이 하나일 경우
	{
		printf("Move  [disc %d]  from <%c>  to  <%c>.\n", n, from, to);
		count++;
	}
	else // 원판이 하나가 아닐 경우
	{
		hanoiTower(n-1, from, to, temp);
		printf("Move  [disc %d]  from <%c>  to  <%c>.\n", n, from, to);
		count++;
		hanoiTower(n-1, temp, from, to);
	}
}
