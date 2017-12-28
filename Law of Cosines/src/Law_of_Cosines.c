//============================================================================
// Name        : Law_of_Cosines.c
// Author      : Minsu Jo
// Created on  : 2016. 3. 22.
// Description : Ansi-style
//============================================================================

/* 삼각형 세 변의 길이가 주어질 때, 코사인 법칙을 이용하여 세 꼭지점의 각도를 구하는 프로그램 */

#include <stdio.h>
#include <math.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	/* 삼각형 ABC의 각 변 길이 정하기 시작 */
	float lenAB; // 변 AB의 길이
	float lenBC; // 변 BC의 길이
	float lenCA; // 변 CA의 길이

	printf("Enter AB length of a triangle ABC : ");
	scanf("%f", &lenAB); // 변 AB의 길이를 입력 받음
	printf("Enter BC length of a triangle ABC : ");
	scanf("%f", &lenBC); // 변 BC의 길이를 입력 받음
	printf("Enter CA length of a triangle ABC : ");
	scanf("%f", &lenCA); // 변 CA의 길이를 입력 받음
	/* 삼각형 ABC의 각 변 길이 정하기 끝 */

	/* 삼각형 ABC의 각 꼭지점의 코사인 값을 코사인 법칙을 이용하여 구하기 시작 */
	float cosA; // 각 A의 코사인 값
	float cosB; // 각 B의 코사인 값
	float cosC; // 각 C의 코사인 값

	cosA = ((lenCA * lenCA) + (lenAB * lenAB) - (lenBC * lenBC)) / (2 * lenCA * lenAB); // 각 A의 코사인 값 정의
	cosB = ((lenAB * lenAB) + (lenBC * lenBC) - (lenCA * lenCA)) / (2 * lenAB * lenBC); // 각 B의 코사인 값 정의
	cosC = ((lenBC * lenBC) + (lenCA * lenCA) - (lenAB * lenAB)) / (2 * lenBC * lenCA); // 각 C의 코사인 값 정의
	/* 삼각형 ABC의 각 꼭지점의 코사인 값을 코사인 법칙을 이용하여 구하기 끝 */

	/* 삼각형 ABC의 각 꼭지점 각도 구하기 시작 */
	float radAngA; // 각 A(라디안각)
	float radAngB; // 각 B(라디안각)
	float radAngC; // 각 C(라디안각)

	float Radian = 180 / M_PI; // 일반 각(도)으로의 변환을 위한 1라디안  = (180/파이)도
	/* 아크코사인(코사인(임의의 각)) = 임의의 각 이라는 사실을 이용 */
	radAngA = acos(cosA) * Radian; // 각 A(라디안각)을 일반각으로 변환, 이제 각 A는 일반각
	radAngB = acos(cosB) * Radian; // 각 B(라디안각)을 일반각으로 변환, 이제 각 B는 일반각
	radAngC = acos(cosC) * Radian; // 각 C(라디안각)을 일반각으로 변환, 이제 각 C는 일반각
	/* 삼각형 ABC의 각 꼭지점 각도 구하기 끝 */

	printf("\n");
	printf("Angle A in degree : %.1f\n", radAngA); // 최대 세자리 숫자인 각 A의 값을 소수점 첫째 자리 까지 표현(소수점 둘째 자리에서 반올림)
	printf("Angle B in degree : %.1f\n", radAngB); // 최대 세자리 숫자인 각 B의 값을 소수점 첫째 자리 까지 표현(소수점 둘째 자리에서 반올림)
	printf("Angle C in degree : %.1f", radAngC); // 최대 세자리 숫자인 각 C의 값을 소수점 첫째 자리 까지 표현(소수점 둘째 자리에서 반올림)

	return 0;
}
