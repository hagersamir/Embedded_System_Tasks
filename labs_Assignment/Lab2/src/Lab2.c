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
////8 for total no of bits of char
//unsigned char right_shift(unsigned char x , int n){
//	return ((x >> n) | (x << (8 - n) ));
//}
//unsigned char left_shift(unsigned char x , int n){
//	return ((x << n) | (x >> (8 - n) ));
//}
//int main(void) {
//	unsigned int x;
//	int n;
//	char option ;
//	printf("Please enter an 8 bit number (in hexadecimal) :");
//	fflush(stdout);
//	scanf("%x",&x);
//	printf("Please enter number of rotate cycles :");
//	fflush(stdout);
//	scanf("%d",&n);
//	printf("Please enter rotate option (Enter 'R' for rotate right or 'L' for rotate left):");
//	fflush(stdout);
//	scanf(" %c",&option);
//
//  switch (option) {
//		case 'R':
//		case 'r':
//			printf("Rotate right %d times : 0x%02x\n", n, right_shift(x, n));
//			break;
//		case 'L':
//		case 'l':
//			printf("Rotate left %d times : 0x%02x\n", n, left_shift(x, n));
//			break;
//		default:
//			printf("Invalid option!\n");
//			return 1;
//	}
//	return 0;
//}


////Q2
//int main(void) {
//int n =5;
////upper triangle diamond
//	for(int i=1;i<=n;i++){
//		for(int space = n; space > i; space--) {
//			printf(" ");
//		}
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

////Q3
//int main(void){
//	int sum = 0 , first_no=0,second_no=1,n;
//	printf("Please enter the no of series : ");
//	fflush(stdout);
//	scanf("%d",&n);
//	printf("%d %d ", first_no, second_no);
//	for(int i=3;i<=n;i++){
//		sum = first_no + second_no;
//		first_no = second_no;
//		second_no = sum;
//		printf("%d ",sum);
//	}
//	return 0;
//}
