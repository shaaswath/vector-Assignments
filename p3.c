#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"


void print_powerof2(struct stu **p , int n){

	int i , j;
	int len = 0;
	int pow = 1;
	
	for(i = 0 ; i < n ; i++){
		len = strlen(p[i] -> name);
		pow = 1;
		if(len == 2){
			printf("The student's marks whose name's length is power of 2 = %.2f\n",p[i] -> marks);
		}
		else {
			for(j = 1 ; j <= len ; j++){
				pow = pow * 2;
			
				if(pow == len){
					printf("The student's marks whose name's length is power of 2 = %.2f\n",p[i] -> marks);
					break;
				}
			}
		}
	}

	printf("-------------------------------------------------------------------------------------------------------------------\n");

}
