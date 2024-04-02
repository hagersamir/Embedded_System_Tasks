/*
 ============================================================================
 Name        : HW1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int main(void) {
	float exp; // exponent can be any real number
	int iterations;
	double result = 1; // initialized with 1 (first term always 1)
	printf("Please enter the exponent value: ");
	fflush(stdout);
	scanf("%f",&exp);
	printf("Please enter the iterations number : ");
	fflush(stdout);
	scanf("%d",&iterations);
	if (iterations > 0)
	{
	for (int i = 1;i < iterations ; i++ ){
		double power_result = 1;
		double fact_result = 1;
		for (int j = 1; j <= i; j ++) // if i == 2
		{
			power_result *= exp;
			fact_result *= j;
		}
		result += power_result / fact_result;
	}

		printf("exp(%0.3f) = %lf\n", exp, result);
	}
	else
	{
		printf("Can't be solved in %d iterations!!", iterations);
	}

	return 0;
}
