//============================================================================
// Name        : Calculation_of_Complex_Number.c
// Author      : Minsu Jo
// Created on  : 2016. 3. 29.
// Description : Ansi-style
//============================================================================

/* 두개의 복소수를 받아서 사칙연산을 하는 프로그램 */

#include <stdio.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char operation; // 입력받을 연산자
	float real_part_1; // 첫번째 복소수의 실수 부분
	float real_part_2; // 두번째 복소수의 실수 부분
	float img_part_1; // 첫번째 복소수의 허수 부분
	float img_part_2; // 두번째 복소수의 허수 부분

	printf("Enter the operation (+, -, *, /): ");
	scanf("%c", &operation); // 연산자 입력 받음

	printf("Enter the first complex number (real part, img part): ");
	scanf("%f %f", &real_part_1, &img_part_1); // 첫번째 복소수의 실수부와 허수부를 입력받음

	printf("Enter the second complex number (real part, img part): ");
	scanf("%f %f", &real_part_2, &img_part_2); // 두번째 복소수의 실수부와 허수부를 입력받음

	if(operation == '+') // '+'연산자를 선택하였을 때
	{
		printf("(%.2f + %.2fi) + (%.2f + %.2fi) = (%.2f + %.2fi)",
				real_part_1, img_part_1, real_part_2, img_part_2,
				real_part_1 + real_part_2, // 실수부 결과
				img_part_1 + img_part_2); // 허수부 결과
	}

	if(operation == '-') // '-'연산자를 선택하였을 때
	{
		printf("(%.2f + %.2fi) - (%.2f + %.2fi) = (%.2f + %.2fi)",
				real_part_1, img_part_1, real_part_2, img_part_2,
				real_part_1 - real_part_2,
				img_part_1 - img_part_2);
	}

	if(operation == '*') // '*'연산자를 선택하였을 때
	{
		printf("(%.2f + %.2fi) * (%.2f + %.2fi) = (%.2f + %.2fi)",
				real_part_1, img_part_1, real_part_2, img_part_2,
				real_part_1 * real_part_2 - img_part_1 * img_part_2,
				img_part_1 * real_part_2 + real_part_1 * img_part_2);
	}

	if(operation == '/') // '*'연산자를 선택하였을 때
	{
		printf("(%.2f + %.2fi) / (%.2f + %.2fi) = (%.2f + %.2fi)",
				real_part_1, img_part_1, real_part_2, img_part_2,
				(real_part_1 * real_part_2 + img_part_1 * img_part_2) / (real_part_2 * real_part_2 + img_part_2 * img_part_2),
				(img_part_1 * real_part_2 - real_part_1 * img_part_2) / (real_part_2 * real_part_2 + img_part_2 * img_part_2));
	}

	return 0;
}
