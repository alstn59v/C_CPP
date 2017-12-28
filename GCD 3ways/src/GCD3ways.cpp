//============================================================================
// Name        : GCD3ways.cpp
// Author      : Minsu Jo
// Created on  : 2017. 11. 2.
// Description : Ansi-style
//============================================================================

/* GCD를 3가지 방법으로 구해보기 */

#include <iostream>
using namespace std;

int gcd_sub(int a, int b);
int gcd_mod(int a, int b);
int gcd_rec(int a, int b);

int main()
{
	int a; // 입력 받을 정수 1
	int b; // 입력 받을 정수 2

	int x; // gcd_sub(a, b)의 값을 저장할 변수
	int y; // gcd_mod(a, b)의 값을 저장할 변수
	int z; // gcd_rec(a, b)의 값을 저장할 변수

	cin >> a >> b;

	x = gcd_sub(a, b);
	y = gcd_mod(a, b);
	z = gcd_rec(a, b);

	cout << "GCD(sub) : " << x << endl;
	cout << "GCD(mod) : " << y << endl;
	cout << "GCD(rec) : " << z << endl;

	return 0;
}

int gcd_sub(int a, int b)
{
	while(a != 0 && b != 0)
	{
		if(a > b)
		{
			a = a - b;
		}
		else
		{
			b = b - a;
		}
	}

	return a + b;
}

int gcd_mod(int a, int b)
{
	while(a != 0 && b != 0)
	{
		if(a > b)
		{
			a = a % b;
		}
		else
		{
			b = b % a;
		}
	}

	return a + b;
}

int gcd_rec(int a, int b)
{
	if(a == b)
	{
		return a;
	}
	else if(a > b)
	{
		return gcd_rec(a - b, b);
	}
	else
	{
		return gcd_rec(a, b - a);
	}
}
