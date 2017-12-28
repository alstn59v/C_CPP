/*
 * Goldbach_Conjecture.cpp
 *
 *  Created on: 2017. 3. 17.
 *      Author: ���μ�
 */

/* 5���� ū Ȧ���� �� �Ҽ��� ������ ǥ���ϱ� */

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n); // �Ҽ��� �Ǻ��ϴ� �Լ� proto type

int main()
{
	int n; // input value
	int count = 0; // �Ҽ��� ����
	bool solution = false; // ���� ���� �Ǻ�(������ true, ������ false)

	cin >> n;

	int primeNums[n] = {0}; // 2���� n���� �Ҽ��� ������ �迭

	for(int divisor = 2, i = 0; divisor < n; divisor++)
	{ // �Ҽ� �Ǻ� ����
		if(isPrime(divisor) == true)
		{ // �Ҽ��� ��� �迭�� �Ҽ��� ����
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
				{ // n - primeNum[k] = �� �Ҽ��� �� �̸� �ذ� �߻��� ��
					cout << primeNums[k] << " " << primeNums[i] <<  " " << primeNums[j] << endl;
					solution = true; // �ذ� ����
					break; // ��(�������� �Ҽ��� �ּ��� �� �Ҽ�)�� �߰��� ��� ������ ��������
				}
			}

			if(solution == true)
			{ // �ظ� ã�� ��� �Ǵٸ� �ظ� ã�� �ʱ� ���� ������ ��������
				break;
			}
		}

		if(solution == true)
		{ // �ظ� ã�� ��� �Ǵٸ� �ظ� ã�� �ʱ� ���� ������ ��������
			break;
		}
	}

	if(solution == false)
	{ // ���������� �ذ� ���� ��� 0�� ���
		cout << 0 << endl;
	}

	return 0;
}

bool isPrime(int n) // �Ҽ��� �Ǻ��ϴ� �Լ� ����
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
