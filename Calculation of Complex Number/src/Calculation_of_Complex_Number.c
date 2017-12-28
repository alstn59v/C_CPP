//============================================================================
// Name        : Calculation_of_Complex_Number.c
// Author      : Minsu Jo
// Created on  : 2016. 3. 29.
// Description : Ansi-style
//============================================================================

/* �ΰ��� ���Ҽ��� �޾Ƽ� ��Ģ������ �ϴ� ���α׷� */

#include <stdio.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char operation; // �Է¹��� ������
	float real_part_1; // ù��° ���Ҽ��� �Ǽ� �κ�
	float real_part_2; // �ι�° ���Ҽ��� �Ǽ� �κ�
	float img_part_1; // ù��° ���Ҽ��� ��� �κ�
	float img_part_2; // �ι�° ���Ҽ��� ��� �κ�

	printf("Enter the operation (+, -, *, /): ");
	scanf("%c", &operation); // ������ �Է� ����

	printf("Enter the first complex number (real part, img part): ");
	scanf("%f %f", &real_part_1, &img_part_1); // ù��° ���Ҽ��� �Ǽ��ο� ����θ� �Է¹���

	printf("Enter the second complex number (real part, img part): ");
	scanf("%f %f", &real_part_2, &img_part_2); // �ι�° ���Ҽ��� �Ǽ��ο� ����θ� �Է¹���

	if(operation == '+') // '+'�����ڸ� �����Ͽ��� ��
	{
		printf("(%.2f + %.2fi) + (%.2f + %.2fi) = (%.2f + %.2fi)",
				real_part_1, img_part_1, real_part_2, img_part_2,
				real_part_1 + real_part_2, // �Ǽ��� ���
				img_part_1 + img_part_2); // ����� ���
	}

	if(operation == '-') // '-'�����ڸ� �����Ͽ��� ��
	{
		printf("(%.2f + %.2fi) - (%.2f + %.2fi) = (%.2f + %.2fi)",
				real_part_1, img_part_1, real_part_2, img_part_2,
				real_part_1 - real_part_2,
				img_part_1 - img_part_2);
	}

	if(operation == '*') // '*'�����ڸ� �����Ͽ��� ��
	{
		printf("(%.2f + %.2fi) * (%.2f + %.2fi) = (%.2f + %.2fi)",
				real_part_1, img_part_1, real_part_2, img_part_2,
				real_part_1 * real_part_2 - img_part_1 * img_part_2,
				img_part_1 * real_part_2 + real_part_1 * img_part_2);
	}

	if(operation == '/') // '*'�����ڸ� �����Ͽ��� ��
	{
		printf("(%.2f + %.2fi) / (%.2f + %.2fi) = (%.2f + %.2fi)",
				real_part_1, img_part_1, real_part_2, img_part_2,
				(real_part_1 * real_part_2 + img_part_1 * img_part_2) / (real_part_2 * real_part_2 + img_part_2 * img_part_2),
				(img_part_1 * real_part_2 - real_part_1 * img_part_2) / (real_part_2 * real_part_2 + img_part_2 * img_part_2));
	}

	return 0;
}
