#include<stdio.h>
#include<stdlib.h>
#include"header.h"
#include<string.h>

void print_Hmarks(struct stu **p , int n){
	
	float Hmarks = p[0] -> marks;
	char Hname[20];
	for(i = 0 ; i <= strlen(p[0]->name) ; i++)
		Hname[i] = p[0]->name[i];

	for(i = 1 ; i < n ; i++){
		if(p[i] -> marks > Hmarks){
			Hmarks = p[i] -> marks;
			for(int j = 0 ; j <= strlen(p[i] -> name) ; j++){

				Hname[j] = p[i] -> name[j];
			}
		}

	}
	printf("The student's data who got highest mark person's name is %s\n",Hname);


	printf("-------------------------------------------------------------------------------------------------------------------\n");
}
