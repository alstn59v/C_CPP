/*
 * Goldbach_Conjecture.cpp
 *
 *  Created on: 2017. 3. 17.
 *      Author: 조민수
 */

/* 5보다 큰 홀수를 세 소수의 합으로 표현하기 */

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n); // 소수를 판별하는 함수 proto type

int main()
{
	int n; // input value
	int count = 0; // 소수의 개수
	bool solution = false; // 해의 존재 판별(있으면 true, 없으면 false)

	cin >> n;

	int primeNums[n] = {0}; // 2부터 n까지 소수를 저장할 배열

	for(int divisor = 2, i = 0; divisor < n; divisor++)
	{ // 소수 판별 과정
		if(isPrime(divisor) == true)
		{ // 소수인 경우 배열에 소수를 저장
			primeNums[i++] = divisor;
			count++;
		}
	}

	for(int k = 0; k < count; k++)
	{
		for(int i = k; i < count; i++)
		{
			for(int j = i; j < count; j++)
			{
				if((n - primeNums[k]) == (primeNums[i] + primeNums[j]))
				{ // n - primeNum[k] = 두 소수의 합 이면 해가 발생된 것
					cout << primeNums[k] << " " << primeNums[i] <<  " " << primeNums[j] << endl;
					solution = true; // 해가 있음
					break; // 해(제일작은 소수가 최소인 세 소수)를 발견한 경우 루프를 빠져나옴
				}
			}

			if(solution == true)
			{ // 해를 찾은 경우 또다른 해를 찾지 않기 위해 루프를 빠져나옴
				break;
			}
		}

		if(solution == true)
		{ // 해를 찾은 경우 또다른 해를 찾지 않기 위해 루프를 빠져나옴
			break;
		}
	}

	if(solution == false)
	{ // 최종적으로 해가 없는 경우 0을 출력
		cout << 0 << endl;
	}

	return 0;
}

bool isPrime(int n) // 소수를 판별하는 함수 정의
{
	if(n == 1)
	{
		return false;
	}

	for(int divisor = 2; divisor <= int(sqrt((double)n)); divisor++)
	{
		if(n % divisor == 0)
		{
			return false;
		}
	}

	return true;
}
