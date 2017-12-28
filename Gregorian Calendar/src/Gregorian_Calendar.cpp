//============================================================================
// Name        : Gregorian_Calendar.cpp
// Author      : Minsu Jo
// Created on  : 2016. 5. 2.
// Description : Ansi-style
//============================================================================

/* 1583년 이후 그레고리 달력에서 줄리언 값을 여러번 계산하여 원하는 년도의 달력 출력 */

#include <iostream>
using namespace std;

int getJulianValue(int year, int month); // julian값을 이용한 기준일로부터 지난 일수를 계산하는 함수
int getMonthsMaxDay(int year, int month); // 윤달과 월별 일수를 고려한 월별 최대 일수를 구하는 함수
void printCalendar(int year, string monthStr, int wd_start, int last); // 월별 달력을 출력하는 함수

int main()
{
	int year; // 년도

	cout << "Enter Gregorian year (year >= 1583): ";
	cin >> year; // 년도 입력 받음

	if(year < 1583) // 년도는 1583년도 부터 시작해야 함
	{
		cout << endl;
		cout << "Enter year >= 1583! Try again!" << endl;
		return 1;
	}

	long julian; // 원년(4714 BC 1월 1일)으로부터 지난 일수

	int max_day_of_month; // 윤달과 월별 일수를 고려한 월별 최대 일수
	int weekday_distinction; // 요일 판별 변수 선언

	int wd_start; //  0: M, 1: T, 2: W, 3: T, 4: F, 5: S, 6: S
	int last; // 마지막 날짜 변수 선언

	string monthStr[12] = {"January", "February", "March", "April", "May", "June",
			"July", "August", "September", "October", "November", "December"};

	cout << endl << endl;

	for(int m = 1; m <= 12; m++)
	{
		julian = getJulianValue(year, m); // julian값을 이용한 기준일로부터 지난 일수 계산
		max_day_of_month = getMonthsMaxDay(year, m); // 윤년을 고려한 월별 일수 판별
		weekday_distinction = julian%7; // 일주일이 7일이므로 나머지 연산자 이용
		wd_start = weekday_distinction; // 시작 요일 변수 초기화
		last = max_day_of_month; // 마지막 날짜 변수 초기화
		printCalendar(year, monthStr[m-1], wd_start, last);
		cout << endl << endl;
	}

	return 0;
}

int getJulianValue(int year, int month)
{ // julian값을 이용한 기준일로부터 지난 일수를 계산하는 함수
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
{ // 윤달과 월별 일수를 고려한 월별 최대 일수를 구하는 함수
	int max_day_of_month; // 윤달과 월별 일수를 고려한 월별 최대 일수

	switch(month) // 입력 받은 월에 따라 일수 판별
	{
	case 2: // 윤년의 여부에 따라 2월의 일수가 달라짐
		if((year%4 == 0 && year%100 != 0) || (year%400 == 0)) // 윤년의 조건이 성립할 때
		{
			max_day_of_month = 29; // 29일 까지
		}
		else // 윤년의 조건이 성립하지 않을 때
		{
			max_day_of_month = 28; // 28일 까지
		}
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		max_day_of_month = 30;
		break; // 4, 6, 9, 11월은 30일 까지
	default: // 나머지 1, 3, 5, 7, 8, 10, 12월
		max_day_of_month = 31;
		break; // 31일 까지
	}

	return max_day_of_month;
}

void printCalendar(int year, string monthStr, int wd_start, int last)
{ // 월별 달력을 출력하는 함수
	cout << "     " << monthStr << " " << year << endl;
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
