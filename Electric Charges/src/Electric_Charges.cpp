//============================================================================
// Name        : Electric_Charges.cpp
// Author      : Minsu Jo
// Created on  : Created on: 2017. 3. 17.
// Description : Ansi-style
//============================================================================

/* �ش� ���� ���� ������ û���ݾ� ���ϱ� */

#include <iostream>
using namespace std;

int electricCharge(int month, int kwh); // electricCharge�Լ� ProtoType

int main()
{
	int month; // ���� ��� ��
	int kwh; // ���� ��뷮

	cout << "Enter the Month : ";
	cin >> month; // ��, ��뷮 �Է� ����

	cout << "Enter the amount of used(kWh) : ";
	cin >> kwh; // ��, ��뷮 �Է� ����

	cout << "Electric charges : " << electricCharge(month, kwh) << " won" << endl; // �Լ� ȣ��

	return 0;
}

int electricCharge(int month, int kwh)
{
	int basicCharge; // �⺻ ���
	float usedCharge; // ��뷮 ���
	const float usedCharge1st200 = 93.3; // ó�� 200kwh���� ��뷮 ���(��/kwh)
	const float usedCharge2nd200 = 187.9; // ���� 200kwh���� ��뷮 ���(��/kwh)
	const float usedChargeOver400 = 280.6; // 400kwh �ʰ��� ��뷮 ���(��/kwh)
	const float usedChargeSuper = 709.5; // �������� ��뷮 ���(��/kwh)
	int elctCharge; // �����ݰ�
	int tax; // ����
	int vat; // �ΰ���ġ��
	int elctIndusFoundFund; // ���»����ݱ��
	int totalCharge; // û�����

	if((month == 1 || month == 2 || month == 7 || month == 8 || month == 12) && (kwh > 1000)) // ���ϰ� �Ǵ�, �������� ��� ����
	{
		basicCharge = 7300; // 400kwh �ʰ��̹Ƿ� �⺻ ����� 7300��
		usedCharge = usedCharge1st200 * 200 + usedCharge2nd200 * 200 + usedChargeOver400 * 600 + usedChargeSuper * (kwh - 1000); // ��뷮 ��� ����
	}
	else
	{
		if(kwh <= 200) // 200kwh���� ���� ���
		{
			basicCharge = 910; // �⺻ ��� ����
			usedCharge = usedCharge1st200 * kwh; // ��뷮 ��� ����
		}
		else if(kwh <= 400) // 201 ~ 400kwh ���� ���
		{
			basicCharge = 1600; // �⺻ ��� ����
			usedCharge = usedCharge1st200 * 200 + usedCharge2nd200 * (kwh - 200); // ó�� 200kwh������ kwh�� ��� �ٸ�
		}
		else // 400kwh�ʰ� ���� ���
		{
			basicCharge = 7300; // �⺻ ��� ����
			usedCharge = usedCharge1st200 * 200 + usedCharge2nd200 * 200 + usedChargeOver400 * (kwh - 400); // ó�� 200kwh, �� ���� 200kwh������ kwh�� ��� �ٸ�
		}
	}

	elctCharge = basicCharge + int(usedCharge); // ���� ��ݰ� = �⺻ ��� + ��뷮 ���(�� ���� �̸� ����)
	vat = int(elctCharge * 0.1 + 0.5); // �ΰ���ġ�� = �����ݰ��� 10%(�� ���� �̸� �ݿø�)
	elctIndusFoundFund = int((elctCharge * 0.037) / 10) * 10; // ���»����ݱ�� = �����ݰ��� 3.7%(10�� �̸� ����)
	tax = vat + elctIndusFoundFund; // ���� = �ΰ���ġ�� + ���»����ݱ��
	totalCharge = int((elctCharge + tax) / 10) * 10; // û����ݰ�(10�� �̸� ����) = �⺻ ��� + ���·� ��� + �ΰ��� + ��ݿ��

	return totalCharge;
}
