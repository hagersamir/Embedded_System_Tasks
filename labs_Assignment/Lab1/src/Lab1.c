/*
 ============================================================================
 Name        : Lab1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>


//Q1
int main(void)
{
	float u, a, t, V, S;

	printf("Please Enter the value of u: ");
    fflush(stdout);
	scanf("%f",&u);
	printf("Please Enter the value of a: ");
    fflush(stdout);
	scanf("%f",&a);
	printf("Please Enter the value of t: ");
    fflush(stdout);
	scanf("%f",&t);

	V = u + (a * t) ;
	S = (u*t) + (0.5 *a*t*t);

	printf("The Value of Final Velocity Is %.3f m/sec \n",V);
	printf("the Value of Distance Is %0.3f m",S);

	return 0;
}

////Q2
//int main(void)
//{
//	int a,b,c;
//	int Sum,Product,Smallest,Largest ;
//	float Average;
//	printf("Enter Three Different integers: ");
//	fflush(stdout);
//	scanf("%d %d %d",&a,&b,&c);
//	Sum = a + b + c;
//	Average = Sum / 3.0;
//	Product = a * b * c;
//	Smallest =  ( a > b ) ? (( b > c) ? c : b) : (( a > c ) ? c : a);
//	Largest =  ( a > b ) ? (( a > c) ? a : c ) : (( b > c ) ? b : c );
//	printf("Sum is : %d\n",Sum);
//	printf("Average is : %.3f\n",Average);
//	printf("Product is %d\n",Product);
//	printf("Smallest is : %d\n", Smallest);
//	printf("Largest is : %d\n", Largest);
//
//	return 0;
//}

////Q3
//int main(void) {
//    int total_sec, hr, min, sec;
//
//    printf("Please Enter The Total Time elapsed in seconds: ");
//    fflush(stdout);
//    if (scanf("%d", &total_sec) != 1 || total_sec < 0) {
//        printf("Invalid input! Please enter a non-negative integer.\n");
//        return 1;
//    }
//    hr = total_sec / 3600;
//    int reminder_min_sec = total_sec % 3600;
//    min = reminder_min_sec / 60;
//    sec = reminder_min_sec % 60;
//
//    printf("Time is %d:%02d:%02d\n", hr, min, sec);
//    return 0;
//}
//
