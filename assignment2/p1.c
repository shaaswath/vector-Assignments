#include<stdio.h>
#include<stdlib.h>
#include"header.h"

void print_rNo(struct stu **p,int n){

	printf("-------------------------------------------------------------------------------------------------------------------\n");

	int i;
	for(i = 0 ; i < n ; i++){
		if((p[i] -> rollNo) % 2 == 0){

			printf("The student's data where the rollNo is even : ");

			printf("rollNo = %d name = %s marks = %.2f\n",p[i] -> rollNo , p[i] -> name , p[i] -> marks);
		}
	}
	printf("-------------------------------------------------------------------------------------------------------------------\n");

}
	
