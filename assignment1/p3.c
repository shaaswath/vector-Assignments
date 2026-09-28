#include<stdio.h>
#include<stdlib.h>
#include<string.h>



struct stu{
	int rollNo;
	char name[20];
	float marks;
};


void print_powerof2(struct stu **p , int n){

	int i , j;
	int len = 0;
	int pow = 1;
	
	printf("-------------------------------------------------------------------------------------------------------------------\n");
	for(i = 0 ; i < n ; i++){
		len = strlen(p[i] -> name);
		pow = 1;
			for(j = 1 ; j <= len ; j++){
				pow = pow * 2;
			
				if(pow == len){
					printf("The student's marks whose name's length is power of 2 = %.2f\n",p[i] -> marks);
					break;
				}
			}
		
	}

	printf("-------------------------------------------------------------------------------------------------------------------\n");

}
