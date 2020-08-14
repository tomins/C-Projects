/**************************************************/
/*                                                */
/* Question 2 - StudentArray.c		               */
/* Name :Thomas Cummins                                        */
/* Class : DT354/2                                  */
/*	 											  */
/**************************************************/
#define _CRT_SECURE_NO_WARNINGS 1
#define bool int
#define false 0
#define true (!false)

#include <stdio.h>
#include <string.h>

#define SIZE 4


//Structure Template
struct student {
	char surname[20];
	char moduleName[20];
	int examResult;
};

//Global Variable
struct student studentDetails[SIZE];

//Function Prototypes
char* findBestStudent(); //find and return the address of the first character of the name of the best student
void findOOSDStudents(); //find and display the number of students studying OOSD

/*  FOR EACH OF THE FUNCTIONS BELOW, YOU ARE ALLOWED TO RENAME OR IGNORE EXISTING VARIABLES;
	OR INCLUDE ANY EXTRA VARIABLES YOU NEED FOR YOUR SOLUTION */

	/***** MAIN FUNCTION *******/
void main()  //CHANGE INT TO VOID IF USING VISUAL STUDIO
{
	bool check = false;
	char* surname;
	struct student stu[SIZE];

	for (int index = 0; index < SIZE; index++)
	{
		
			printf("Input Surname :\n");
			gets(stu[index].surname);
		
			
		

		printf("Input module name : \n");
		gets(stu[index].moduleName);

		printf("Input exam result : \n");
		scanf("%d", &stu[index].examResult);
		getchar();
		
		


		//ADD CODE HERE TO ASK USER TO INPUT THE 4 STUDENTS MAKING SURE THAT NO 
	//STUDENTS HAVE THE SAME NAME

	}


	//Call the other functions
	surname = findBestStudent(stu);
	printf("Student with surname %s has the highest exam result\n\n", surname);

	findOOSDStudents(stu);

	getchar();
	getchar();
	//ADD return 0; if using the online compiler
}//end main


// COMPLETE THE FOLLOWING FUNCTIONS 

//Find and return the surname of the student with the highest exam result.
//You can assume that the exam results are all different, you don't need to check for this.
char* findBestStudent(struct student* stu) {

	char name[20];
	int bestResult = 0;
	int bestIndex = 0;
	for (int index = 0; index < SIZE; index++)
	{
		if (stu[index].examResult > bestResult) {
			bestResult = stu[index].examResult;
			bestIndex = index;
		}
	}
	
		strcpy(name, stu[bestIndex].surname);


	//ADD CODE HERE 

	return name;

}//end findBestStudent


//Find and display the number of students studying OOSD
void findOOSDStudents(struct student* stu) {
	int counter = 0;
	//ADD CODE HERE
	for (int index = 0; index < SIZE; index++)
	{
		if(strcmp(stu[index].moduleName, "OOSD"))
			counter++;
	}
	printf("Number of OOSD Students is : %d", counter );

} //end findOOSDStudent

bool checker(char surname[20], struct student *stu) {
	
	for (int index = 0; index < SIZE; index++)
	{
		if (strcmp(stu[index].surname, surname))
			return true;
		}
	
}
