/*
 ============================================================================
 Name        : Lab2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

////Q1
//int main(void) {
//	unsigned int x;
//	int n;
//	char option ;
//	printf("Please enter an 8 bit number (in hexadecimal) :");
//	fflush(stdout);
//    if (scanf("%x", &x) != 1 || x > 0xFF) {
//        printf("Invalid input! Please enter an 8-bit hexadecimal number.\n");
//        return 1;
//    }
//	printf("Please enter number of rotate cycles :");
//	fflush(stdout);
//    if (scanf("%d", &n) != 1 || n < 0) {
//        printf("Invalid input! Please enter a non-negative integer.\n");
//        return 1;
//    }
//	printf("Please enter rotate option (Enter 'R' for rotate right or 'L' for rotate left):");
//	fflush(stdout);
//	scanf(" %c",&option);
//
//  switch (option) {
//		case 'R':
//		case 'r':
// 	unsigned char right_shift = ((x >> n) | (x << (8 - n) )); // applying bit masking using or operator.
//			printf("Rotate right %d times : 0x%02x\n", n, right_shift);
//			break;
//		case 'L':
//		case 'l':
//			unsigned char left_shift = ((x << n) | (x >> (8 - n) ));
//			printf("Rotate left %d times : 0x%02x\n", n, left_shift);
//			break;
//		default:
//			printf("Invalid option!\n");
//			return 1;
//	}
//	return 0;
//}
//

////Q2
//int main(void) {
//int n =5;
////upper triangle diamond
//	for(int i=1;i<=n;i++){
//		// for setting the spaces
//		for(int space = n; space > i; space--) {
//			printf(" ");
//		}
//		// for setting the asterisks
//		for (int ast=1 ; ast<=(2*i)-1 ;ast++){
//			printf("*");
//		}
//		printf("\n");
//	}
////lower triangle diamond
//	for(int i=1;i<=n-1;i++){
//		for (int space =1;space <=i ;space++){
//			printf(" ");
//		}
//		for(int ast= 1;ast<= (2 * (n - i)) - 1 ; ast++){
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}

//Q3
int main(void)
{
    long long sum = 0, first_no = 0, second_no = 1; // Using long long as Fibonacci numbers grow exponentially
    int n;

    printf("Please enter the required number of terms in the series: ");
    fflush(stdout);
    scanf("%d", &n);

    if (n == 0)
	{
        printf(" ");
        return 0;
	}
    if (n < 0) {
        printf("Number of terms in the series should be non-negative.\n");
        return 1;
    }

	if (n == 1) {
		printf("%lld ", first_no);
		  }
	else {
		if (n < 93) // the term at which the long long overflow
		{	printf("%lld %lld ", first_no, second_no);
			for (int i = 3; i <= n; i++) {
				sum = first_no + second_no;
				first_no = second_no;
				second_no = sum;
				printf("%lld ", sum);
				}
		}
		else
		{
	        printf("Up to this number of terms, the function behavior is unexpected due to storage limitation.\n");
	        return 1;
		}
		}

    return 0;
}
