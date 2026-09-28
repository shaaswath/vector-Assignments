#include<stdio.h>
#include<stdlib.h>


struct stu{
	int rollNo;
	char name[20];
	float marks;
};


void print_fail(struct stu **p , int n){
	printf("-------------------------------------------------------------------------------------------------------------------\n");
	int i;
	for(i = 0 ; i < n ; i++){
		if(p[i] -> marks <= 45)
			printf("%d %s %.2f\n",p[i] -> rollNo , p[i] -> name , p[i] -> marks);
	}
}

