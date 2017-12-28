//============================================================================
// Name        : Law_of_Cosines.c
// Author      : Minsu Jo
// Created on  : 2016. 3. 22.
// Description : Ansi-style
//============================================================================

/* �ﰢ�� �� ���� ���̰� �־��� ��, �ڻ��� ��Ģ�� �̿��Ͽ� �� �������� ������ ���ϴ� ���α׷� */

#include <stdio.h>
#include <math.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	/* �ﰢ�� ABC�� �� �� ���� ���ϱ� ���� */
	float lenAB; // �� AB�� ����
	float lenBC; // �� BC�� ����
	float lenCA; // �� CA�� ����

	printf("Enter AB length of a triangle ABC : ");
	scanf("%f", &lenAB); // �� AB�� ���̸� �Է� ����
	printf("Enter BC length of a triangle ABC : ");
	scanf("%f", &lenBC); // �� BC�� ���̸� �Է� ����
	printf("Enter CA length of a triangle ABC : ");
	scanf("%f", &lenCA); // �� CA�� ���̸� �Է� ����
	/* �ﰢ�� ABC�� �� �� ���� ���ϱ� �� */

	/* �ﰢ�� ABC�� �� �������� �ڻ��� ���� �ڻ��� ��Ģ�� �̿��Ͽ� ���ϱ� ���� */
	float cosA; // �� A�� �ڻ��� ��
	float cosB; // �� B�� �ڻ��� ��
	float cosC; // �� C�� �ڻ��� ��

	cosA = ((lenCA * lenCA) + (lenAB * lenAB) - (lenBC * lenBC)) / (2 * lenCA * lenAB); // �� A�� �ڻ��� �� ����
	cosB = ((lenAB * lenAB) + (lenBC * lenBC) - (lenCA * lenCA)) / (2 * lenAB * lenBC); // �� B�� �ڻ��� �� ����
	cosC = ((lenBC * lenBC) + (lenCA * lenCA) - (lenAB * lenAB)) / (2 * lenBC * lenCA); // �� C�� �ڻ��� �� ����
	/* �ﰢ�� ABC�� �� �������� �ڻ��� ���� �ڻ��� ��Ģ�� �̿��Ͽ� ���ϱ� �� */

	/* �ﰢ�� ABC�� �� ������ ���� ���ϱ� ���� */
	float radAngA; // �� A(���Ȱ�)
	float radAngB; // �� B(���Ȱ�)
	float radAngC; // �� C(���Ȱ�)

	float Radian = 180 / M_PI; // �Ϲ� ��(��)������ ��ȯ�� ���� 1����  = (180/����)��
	/* ��ũ�ڻ���(�ڻ���(������ ��)) = ������ �� �̶�� ����� �̿� */
	radAngA = acos(cosA) * Radian; // �� A(���Ȱ�)�� �Ϲݰ����� ��ȯ, ���� �� A�� �Ϲݰ�
	radAngB = acos(cosB) * Radian; // �� B(���Ȱ�)�� �Ϲݰ����� ��ȯ, ���� �� B�� �Ϲݰ�
	radAngC = acos(cosC) * Radian; // �� C(���Ȱ�)�� �Ϲݰ����� ��ȯ, ���� �� C�� �Ϲݰ�
	/* �ﰢ�� ABC�� �� ������ ���� ���ϱ� �� */

	printf("\n");
	printf("Angle A in degree : %.1f\n", radAngA); // �ִ� ���ڸ� ������ �� A�� ���� �Ҽ��� ù° �ڸ� ���� ǥ��(�Ҽ��� ��° �ڸ����� �ݿø�)
	printf("Angle B in degree : %.1f\n", radAngB); // �ִ� ���ڸ� ������ �� B�� ���� �Ҽ��� ù° �ڸ� ���� ǥ��(�Ҽ��� ��° �ڸ����� �ݿø�)
	printf("Angle C in degree : %.1f", radAngC); // �ִ� ���ڸ� ������ �� C�� ���� �Ҽ��� ù° �ڸ� ���� ǥ��(�Ҽ��� ��° �ڸ����� �ݿø�)

	return 0;
}
