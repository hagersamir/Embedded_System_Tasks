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
	int u,a,t;
	float V,S ;

	printf("Please Enter the value of u: ");
    fflush(stdout);
	scanf("%d",&u);
	printf("Please Enter the value of a: ");
    fflush(stdout);
	scanf("%d",&a);
	printf("Please Enter the value of t: ");
    fflush(stdout);
	scanf("%d",&t);

	V = u + (a * t) ;
	S = (u*t) + (0.5 *a*t*t);

	printf("The Value of Final Velocity Is %f m/sec \n",V);
	printf("the Value of Distance Is %f m",S);
	return 0;
}

////Q2
//int main(void)
//{
//	int a,b,c;
//	int Sum,Average,Product,Smallest,Largest ;
//	printf("Enter Three Different integers: ");
//	fflush(stdout);
//	scanf("%d %d %d",&a,&b,&c);
//	Sum = a + b+ c;
//	Average = (a + b + c) / 3;
//	Product = a * b *c;
//	Smallest = Largest = a;
//	Smallest = (Smallest > b)? b : Smallest ;
//	Smallest = (Smallest > c)? c : Smallest ;
//	Largest = (Largest <b )? b: Largest ;
//	Largest = (Largest <c )? c: Largest ;
//	printf("Sum is : %d\n",Sum);
//	printf("Average is : %d\n",Average);
//	printf("Product is %d\n",Product);
//	printf("Smallest is : %d\n", Smallest);
//	printf("Largest is : %d\n", Largest);
//
//	return 0;
//}

////Q3
//int main(void)
//{
//	int total_sec,hr,min,sec;
//	printf("Please Enter The Total Time elapsed in second : ");
//	fflush(stdout);
//	scanf("%d",&total_sec);
//	hr = total_sec /3600;
//	int reminder_min_sec = total_sec % 3600;
//	min = reminder_min_sec/60;
//	sec = reminder_min_sec % 60;
//	printf("Time is %d : %d : %d",hr,min,sec);
//	return 0;
//}


