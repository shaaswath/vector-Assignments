#include<stdio.h>
#include<stdlib.h>


struct stu{
	int rollNo;
	char name[20];
	float marks;
};

void print_Hmarks(struct stu **p , int n){
	int i;
	float Hmarks = p[0] -> marks;
	printf("-------------------------------------------------------------------------------------------------------------------\n");
	for(i = 1 ; i < n ; i++){
		if(p[i] -> marks > Hmarks)
			Hmarks = p[i] -> marks;
	}
	for(i = 0 ; i < n ; i++){
		if(Hmarks == p[i] -> marks)
			printf("The student's data who got highest mark person's name is %s\n",p[i] -> name);
	}


	printf("-------------------------------------------------------------------------------------------------------------------\n");
}
