//============================================================================
// Name        : Gregorian_Calendar.cpp
// Author      : Minsu Jo
// Created on  : 2016. 5. 2.
// Description : Ansi-style
//============================================================================

/* 1583�� ���� �׷��� �޷¿��� �ٸ��� ���� ������ ����Ͽ� ���ϴ� �⵵�� �޷� ��� */

#include <iostream>
using namespace std;

int getJulianValue(int year, int month); // julian���� �̿��� �����Ϸκ��� ���� �ϼ��� ����ϴ� �Լ�
int getMonthsMaxDay(int year, int month); // ���ް� ���� �ϼ��� ����� ���� �ִ� �ϼ��� ���ϴ� �Լ�
void printCalendar(int wd_start, int last); // ���� �޷��� ����ϴ� �Լ�

int main()
{
	int year; // �⵵

	cout << "Enter Gregorian year (year >= 1583): ";
	cin >> year; // �⵵ �Է� ����

	if(year < 1583) // �⵵�� 1583�⵵ ���� �����ؾ� ��
	{
		cout << endl;
		cout << "Enter year >= 1583! Try again!" << endl;
		return 1;
	}

	long julian; // ����(4714 BC 1�� 1��)���κ��� ���� �ϼ�

	int max_day_of_month; // ���ް� ���� �ϼ��� ����� ���� �ִ� �ϼ�
	int weekday_distinction; // ���� �Ǻ� ���� ����

	int wd_start; //  0: M, 1: T, 2: W, 3: T, 4: F, 5: S, 6: S
	int last; // ������ ��¥ ���� ����

	string monthStr[12] = {"January", "February", "March", "April", "May", "June",
			"July", "August", "September", "October", "November", "December"};

	cout << endl << endl;

	for(int m = 1; m <= 12; m++)
	{
		julian = getJulianValue(year, m); // julian���� �̿��� �����Ϸκ��� ���� �ϼ� ���
		max_day_of_month = getMonthsMaxDay(year, m); // ������ ����� ���� �ϼ� �Ǻ�
		weekday_distinction = julian%7; // �������� 7���̹Ƿ� ������ ������ �̿�
		wd_start = weekday_distinction; // ���� ���� ���� �ʱ�ȭ
		last = max_day_of_month; // ������ ��¥ ���� �ʱ�ȭ
		cout << "     " << monthStr[m-1] << " " << year << endl;
		printCalendar(wd_start, last);
		cout << endl << endl;
	}

	return 0;
}

int getJulianValue(int year, int month)
{ // julian���� �̿��� �����Ϸκ��� ���� �ϼ��� ����ϴ� �Լ�
	int day = 1;
	year += 8000;

	if(month < 3)
	{
		year--;
		month += 12;
	}

	int julian = (year*365)+(year/4)-(year/100)+(year/400)-1200820+((month*153+3)/5)-92+(day-1);

	return julian;
}

int getMonthsMaxDay(int year, int month)
{ // ���ް� ���� �ϼ��� ����� ���� �ִ� �ϼ��� ���ϴ� �Լ�
	int max_day_of_month; // ���ް� ���� �ϼ��� ����� ���� �ִ� �ϼ�

	switch(month) // �Է� ���� ���� ���� �ϼ� �Ǻ�
	{
	case 2: // ������ ���ο� ���� 2���� �ϼ��� �޶���
		if((year%4 == 0 && year%100 != 0) || (year%400 == 0)) // ������ ������ ������ ��
		{
			max_day_of_month = 29; // 29�� ����
		}
		else // ������ ������ �������� ���� ��
		{
			max_day_of_month = 28; // 28�� ����
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		max_day_of_month = 30;
		break; // 4, 6, 9, 11���� 30�� ����
	default: // ������ 1, 3, 5, 7, 8, 10, 12��
		max_day_of_month = 31;
		break; // 31�� ����
	}

	return max_day_of_month;
}

void printCalendar(int wd_start, int last)
{ // ���� �޷��� ����ϴ� �Լ�
	cout << "  M  T  W  T  F  S  S" << endl; // Mon Tue Wed Thur Fri Sat Sun
	for(int i = 1-wd_start; i <= last; i++)
	{
		if(i <= 0)
		{
			cout << "   ";
		}
		else
		{
			cout.width(3);
			cout << i;
		}
		if(i != last)
		{
			if((i+wd_start)%7 == 0)
			{
				cout << endl;
			}
		}
	}
}
