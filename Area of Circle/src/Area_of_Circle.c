//============================================================================
// Name        : Area_of_Circle.c
// Author      : Minsu Jo
// Created on  : 2016. 3. 17.
// Description : Ansi-style
//============================================================================

/* This Program calculate area of circle.
 * If you input radius of circle, you can get area of circle.
 */

#include <stdio.h>
#include <math.h>

int main()
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	float radius; // radius of circle
	float area; // area of circle

	printf("Please enter the radius : ");
	scanf("%f", &radius);

	area = M_PI * radius * radius; // Define circle's area

	printf("Area is %f\n", area);

	return 0;
}
