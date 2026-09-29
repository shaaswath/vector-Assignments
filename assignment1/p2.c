#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct stu{
	int rollNo;
	char name[20];
	float marks;
};


void print_rm(struct stu **p , int n){
	
	char start , end;
	for(int i = 0 ; i < n ; i++){
	
			start  = p[i] -> name[0];
			end = p[i]->name[strlen(p[i]->name)-1];
			if((start == 'a' || start == 'e' || start == 'i' || start == 'o'|| start == 'u') && (end == 'a' || end == 'e' || end == 'i' || end == 'o' || end == 'u'))
			{
				printf("The student's data where the name starts and ends with vowel : ");
				printf("rollNo = %d  marks  = %.2f\n",p[i] -> rollNo , p[i] -> marks);
			}
	}
}


