//============================================================================
// Name        : GCD3ways.cpp
// Author      : Minsu Jo
// Created on  : 2017. 11. 2.
// Description : Ansi-style
//============================================================================

/* GCD�� 3���� ������� ���غ��� */

#include <iostream>
using namespace std;

int gcd_sub(int a, int b);
int gcd_mod(int a, int b);
int gcd_rec(int a, int b);

int main()
{
	int a; // �Է� ���� ���� 1
	int b; // �Է� ���� ���� 2

	int x; // gcd_sub(a, b)�� ���� ������ ����
	int y; // gcd_mod(a, b)�� ���� ������ ����
	int z; // gcd_rec(a, b)�� ���� ������ ����

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
