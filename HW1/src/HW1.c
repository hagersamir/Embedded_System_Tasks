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
#include <math.h>

float fact(int n){
	if((n==0)|| (n==1)){
		return 1;
		}
	else{
		return (n * fact(n-1));
	}

}
int main(void) {
	int exp,iterations;
	double result=0;
	printf("Please enter the exponent value: ");
	fflush(stdout);
	scanf("%d",&exp);
	printf("Please enter the iterations number : ");
	fflush(stdout);
	scanf("%d",&iterations);
	for (int i = 0;i <= iterations ; i++ ){
		result += (pow(exp,i)/fact(i));
	}
	printf("e^%d = %lf\n",exp,result);
	return 0;
}
