//**************************************************/
//
// Question 3 - NumberLinked.c                   */
//Name : Thomas Cummins                                        */
// Class : DT354/2                                */
//												  */
//**************************************************/
#define _CRT_SECURE_NO_WARNINGS 1
#define bool int
#define false 0
#define true (!false)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10


//Structure Template
struct data {
	int num;
};

struct LinearNode {
	struct data* element;
	struct LinearNode* next;
};


//Global Variable - pointers to first and last elements in the list
struct LinearNode* list = NULL;  //pointer to the first element in the list
struct LinearNode* last = NULL;  //pointer to the last element in the list



//Function Prototypes
void addNumber();
void displayNumbers();
void reverseNumbers();
bool isEmpty();

/*  FOR EACH OF THE FUNCTIONS BELOW, YOU ARE ALLOWED TO RENAME OR IGNORE EXISTING VARIABLES;
	OR INCLUDE ANY EXTRA VARIABLES YOU NEED FOR YOUR SOLUTION */

	/***** MAIN FUNCTION *******/
int main() //CHANGE INT TO VOID IF USING VISUAL STUDIO
{
	//Input 10 numbers into the linked list
	for (int index = 0; index < SIZE; index++) {
		printf("\n****** Enter Details for element %d ********\n", index + 1);
		addNumber();
		printf("****** Finished with element %d\n\n", index + 1);
	}

	displayNumbers();
	reverseNumbers();

	getchar();
	getchar();

	//ADD return 0; if using the online compiler
} //end main



// check to see if the list is empty
// the function returns true or false.
bool isEmpty()
{
	if (list == NULL)
		return true;
	else
		return false;
}



/*** COMPLETE THE FOLLOWING FUNCTIONS ***/

//ADD A NEW ELEMENT TO THE FRONT OF THE LIST
void addNumber()
{
	int aNumber;
	struct LinearNode* aNode;
	struct data* anElement;

	printf("Enter a number: ");
	scanf("%d", &aNumber);

	// create space for new node
	aNode = (struct LinearNode*)malloc(sizeof(struct LinearNode));
	anElement = (struct data*)malloc(sizeof(struct data));

	if (aNode == NULL || anElement == NULL)
		printf("Error - no space for the new node\n");
	else { // add data part to the node
		anElement->num = aNumber;
		aNode->element = anElement;
		aNode->next = NULL;
	}//end else

// INSERT THE REST OF THE CODE HERE TO ADD THE NEW NODE
	//  TO THE FRONT OF THE LIST
	if (isEmpty())
	{
		list = aNode;
		last = aNode;
	}
	else {
		last->next = aNode;
		last = aNode;
	} //end else

}//end addNumber



// DISPLAY FIRST, FOURTH, FIFTH, EIGHTH and NINTH NUMBERS IN THE LIST
void displayNumbers() {
	struct LinearNode* current;
	current = list;
	int index = 0;
	while (current != NULL) {
		if (index == 0 || index == 3 || index == 4 || index == 7 || index == 8) {
			printf("%d\n", current->element->num);
			
		}
		index++;
		current = current->next;
	}
	//ADD CODE HERE

}//end displayNumber


// CREATE AND DISPLAY A NEW LIST
void reverseNumbers() {
	struct LinearNode* current;
	current = list;

	
	
		struct LinearNode* aNode;
		struct data* anElement;

		struct LinearNode* firstNewList;  //pointer to first element in new List
		struct LinearNode* lastNewList;  //pointer to first element in new List

		while (current != NULL) {
		// create space for new node
		aNode = (struct LinearNode*)malloc(sizeof(struct LinearNode));
		anElement = (struct data*)malloc(sizeof(struct data));


		
		aNode->element = current->element;
		aNode->next = NULL;


		
		if (isEmpty())
		{
			firstNewList = aNode;
			lastNewList = aNode;
		}
		else {
			lastNewList->next = aNode;
			lastNewList = aNode;
		} //end else
		current = current->next;
	}


		while (aNode != NULL) {
			
				printf("%d\n", current->element->num);

			
			aNode = aNode->next;
		}


//ADD CODE HERE

}//end reverseNumbers
