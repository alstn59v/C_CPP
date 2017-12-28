/*
 * Electric_Charges.cpp
 *
 *  Created on: 2017. 3. 17.
 *      Author: 조민수
 */

/* 해당 월의 주택 전기요금 청구금액 구하기 */

#include <iostream>
using namespace std;

int electricCharge(int month, int kwh); // electricCharge함수 ProtoType

int main()
{
	int month; // 전기 사용 월
	int kwh; // 전기 사용량

	cout << "Enter the Month : ";
	cin >> month; // 월, 사용량 입력 받음

	cout << "Enter the amount of used(kWh) : ";
	cin >> kwh; // 월, 사용량 입력 받음

	cout << "Electric charges : " << electricCharge(month, kwh) << " won" << endl; // 함수 호출

	return 0;
}

int electricCharge(int month, int kwh)
{
	int basicCharge; // 기본 요금
	float usedCharge; // 사용량 요금
	const float usedCharge1st200 = 93.3; // 처음 200kwh까지 사용량 요금(원/kwh)
	const float usedCharge2nd200 = 187.9; // 다음 200kwh까지 사용량 요금(원/kwh)
	const float usedChargeOver400 = 280.6; // 400kwh 초과시 사용량 요금(원/kwh)
	const float usedChargeSuper = 709.5; // 슈퍼유저 사용량 요금(원/kwh)
	int elctCharge; // 전기요금계
	int tax; // 세금
	int vat; // 부가가치세
	int elctIndusFoundFund; // 전력산업기반기금
	int totalCharge; // 청구요금

	if((month == 1 || month == 2 || month == 7 || month == 8 || month == 12) && (kwh > 1000)) // 동하계 판단, 슈퍼유저 요금 때문
	{
		basicCharge = 7300; // 400kwh 초과이므로 기본 요금은 7300원
		usedCharge = usedCharge1st200 * 200 + usedCharge2nd200 * 200 + usedChargeOver400 * 600 + usedChargeSuper * (kwh - 1000); // 사용량 요금 정의
	}
	else
	{
		if(kwh <= 200) // 200kwh이하 사용시 요금
		{
			basicCharge = 910; // 기본 요금 정의
			usedCharge = usedCharge1st200 * kwh; // 사용량 요금 정의
		}
		else if(kwh <= 400) // 201 ~ 400kwh 사용시 요금
		{
			basicCharge = 1600; // 기본 요금 정의
			usedCharge = usedCharge1st200 * 200 + usedCharge2nd200 * (kwh - 200); // 처음 200kwh까지는 kwh당 요금 다름
		}
		else // 400kwh초과 사용시 요금
		{
			basicCharge = 7300; // 기본 요금 정의
			usedCharge = usedCharge1st200 * 200 + usedCharge2nd200 * 200 + usedChargeOver400 * (kwh - 400); // 처음 200kwh, 그 다음 200kwh까지는 kwh당 요금 다름
		}
	}

	elctCharge = basicCharge + int(usedCharge); // 전기 요금계 = 기본 요금 + 사용량 요금(원 단위 미만 절사)
	vat = int(elctCharge * 0.1 + 0.5); // 부가가치세 = 전기요금계의 10%(원 단위 미만 반올림)
	elctIndusFoundFund = int((elctCharge * 0.037) / 10) * 10; // 전력산업기반기금 = 전기요금계의 3.7%(10원 미만 절사)
	tax = vat + elctIndusFoundFund; // 세금 = 부가가치세 + 전력산업기반기금
	totalCharge = int((elctCharge + tax) / 10) * 10; // 청구요금계(10원 미만 절사) = 기본 요금 + 전력량 요금 + 부가세 + 기반요금

	return totalCharge;
}
