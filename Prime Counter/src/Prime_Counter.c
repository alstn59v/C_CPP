/*
 * Prime_Counter.c
 *
 *  Created on: 2016. 5. 24.
 *      Author: 조민수
 */

/* 함수를 이용한 2부터 n까지 소수의 개수 구하기 */

#include <stdio.h>
#include <math.h>

int is_prime(int n); // 소수 판별 함수 prototype
int prime_count(int n); // 소수의 개수를 구하는 함수 prototype

int main()
{
	int n; // 입력받을 변수 선언

	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	printf("Please enter an integer number (>=2): ");
	scanf("%d", &n);

	printf("The number of prime numbers between 2 and %d is %d", n, prime_count(n));

	return 0;
}

int is_prime(int n) // 소수 판별 함수
{
	int number_aliquot = 0; // 약수의 개수 변수 선언 및 초기화
	int divisor; // 나눌 수 변수 선언

	for(divisor = 1; divisor <= floor(sqrt(n)); divisor++)
	{ // 소수는 sqrt(n)보다 작은데서 약수를 1밖에 가지지 않음
		if(n % divisor == 0) // n이 나눠떨어질 경우
		{
			number_aliquot++; // 약수의 개수 1증가

			if(number_aliquot >= 2) // 1부터 sqrt(n)사이에 약수의 개수가 2개 부터는 소수가 아님
			{
				return 0; // 루프 중단 -> 실행 속도가 개선됨
			}
		}
	}

	return (number_aliquot == 1); // true(소수일 경우)이면 1, false(소수가 아닐 경우)이면 0을 반환
}

int prime_count(int n) // 소수의 개수를 구하는 함수
{
	static int number_prime = 0; // 소수의 개수 변수 선언 및 초기화
	int i; // index number 변수 선언

	for(i = 2; i <= n; i++) // 소수는 2부터 시작하고 n까지 판별해야 함
	{
		if(is_prime(i) == 1) // 소수일 경우
		{
			number_prime++; // 소수의 개수 1증가
		}
	}

	return number_prime; // 소수의 개수 반환
}
