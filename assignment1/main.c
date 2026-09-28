#include<stdio.h>
#include<stdlib.h>

	static int n; // no. of student's data


// structure declaration 

struct stu{
	int rollNo;
	char name[20];
	float marks;
};

// function declaration

extern void print_rNo(struct stu ** , int);
extern void print_rm(struct stu ** , int);
extern void print_Hmarks(struct stu ** , int);
extern void print_compMarks(struct stu ** , int);
extern void print_powerof2(struct stu ** , int);
extern void print_fail(struct stu ** , int);


int main(){
	struct stu **p;
	printf("Enter no. of student's data : ");
//	printf("\n");
	scanf("%d", &n);
	printf("\n");


	p = malloc(sizeof(struct stu *)*n);

	int i;

	for(i = 0 ; i < n ; i++)
		p[i] = malloc(sizeof(struct stu));

	// getting input for struct stu at runtime
	for(i = 0 ; i < n ; i++){
		printf("Enter the student's data rollNo , name , marks : ");
		scanf("%d %s %f",&p[i] -> rollNo , p[i] -> name , &p[i] -> marks);
	}
	
	printf("-------------------------------------------------------------------------------------------------------------------\n");
	

	// menu based 
	int option;
	
	printf("-------------------------------------------------------------------------------------------------------------------\n");
	printf("OPTION 1 : PRINT RNO , NAME & MARKS IF(RNO EVEN)\n");
	printf("OPTION 2 : PRINT RNO , MARKS IF(NAME 1ST AND LAST IS VOWEL)\n");
	printf("OPTION 3 : PRINT MARKS  IF(NAME LENGTH IS POWER OF 2)\n");
	printf("OPTION 4 : PRINT NAME WHO GOT HIGHEST MARKS\n");
        printf("OPTION 5 : PRINT RNO , NAME IF(MARKS B/W 45 TO 85)\n");
	printf("OPTION 6 : PRINT RNO , NAME & MARKS IF(MARKS < 35)\n");
		


	printf("-------------------------------------------------------------------------------------------------------------------\n");
	printf("Enter which task you need to perform : ");
	scanf("%d",&option);



	// function call 
	switch(option){
		case(1) :	{
					print_rNo(p , n); 
					break;
				}// printing the rNo , name , marks whose rNo is even number 	
		case(2) :	{
					print_rm(p,n); // printing the rNo , marks whose name is starts and ends with vowel 
					break;
				}
		case(3) :	{
					print_powerof2(p,n); // printing the name of the student who got high marks
					break;
				}
		case(4) :	{
					print_Hmarks(p,n); // printing the rNo and name of the student's marks between 45 to 85
					break;
				}

		case(5) : 	{
					print_compMarks(p,n); // printing the marks whose name's length is power of 2
					break;
				}
		case(6) : 	{
					print_fail(p,n); // printing the rNo,name & marks whose marks is less than or equal to 45
					break;
				}
		default :
				printf("Enter valid option!...");
	}


	return 0;

}
