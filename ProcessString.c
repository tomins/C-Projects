/**************************************************/
/*                                                */
/* Question 1 - ProcessString.c                 */
/*                                              */
/* Name : Thomas Cummins                                        */
/* Class : DT354/2                                 */
/*												  */
/************************* *************************/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

/* YOU ARE ALLOWED TO RENAME OR IGNORE EXISTING VARIABLES; OR INCLUDE ANY EXTRA VARIABLES YOU NEED FOR YOUR SOLUTION */

int main()  //CHANGE INT TO VOID IF USING VISUAL STUDIO
{
	char theString[40];  //These are a sample selection of variables. 
	int numberOfWords = 1;//You are free to ignore these and use your own variables
	int index = 0;

	printf("Please enter a sentence with at least one space between each word: ");
	fflush(stdin); fflush(stdin);  //clear the scanner
	fgets(theString, 40, stdin);  //THIS COMMAND ALLOWS A STRING TO BE INPUT WITH SPACES

	//ADD CODE HERE TO COUNT THE NUMBER OF WORDS
	for (int i = 0; i < strlen(theString); i++) {
		char charater = theString[i];
		if (charater == ' '  )
			numberOfWords++;
	}
	//IN THE STRING


	printf("\n\nNumber of Words : %d\n", numberOfWords);

	//ADD CODE HERE TO REPLACE VOWELS
	for (int i = 0; i < strlen(theString); i++) {
		switch (theString[i]) {
		case 'a':
		case 'e':
		case'i':
		case 'o':
		case 'u':
			theString[i] = '?'; break;
		}
	}
	//WITH ? SYMBOL


	printf("\n\nThe sentence is : %s\n", theString);
	getchar();
	getchar();

	//ADD return 0; if using the online compiler
}// end main

