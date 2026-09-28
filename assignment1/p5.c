#include<stdio.h>
#include<stdlib.h>

struct stu{
	int rollNo;
	char name[20];
	float marks;
};

void print_compMarks(struct stu **p , int n){
	printf("-------------------------------------------------------------------------------------------------------------------\n");
	int i;
	for(i = 0 ; i < n ; i++)
		if((p[i] -> marks >= 45) && (p[i] -> marks <= 85))
			printf("The student's data whose marks is between 45 to 85 is rollNo = %d name = %s\n",p[i]->rollNo , p[i] -> name);

	printf("-------------------------------------------------------------------------------------------------------------------\n");
}
