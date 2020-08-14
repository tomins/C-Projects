/*Thomas Cummins
  C18473984*/

#define _CRT_SECURE_NO_WARNINGS 1 //ensures scanf can be used
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

//Structure for a Car object
struct car { 
	char reg[8], make[15], model[15], colour[10];
	int previousOwners, reserveAmt;
	bool reserved;
};
//Structure for a linked list node
struct LinearNode {
	struct car *element;
	struct LinearNode *next;
};
struct LinearNode *front = NULL;//Front node of the linked list
struct LinearNode *last = NULL;//last node



//method prototypes
void inputCar();//add a car to the linkedList
void menu();//Main menu of the program
void main();
bool checkReg(char);  //adding nodes to front of the list
bool isEmpty(); //checking if the linkedList is empty
bool isReserved(struct LinearNode *);//checking if a particular car is reserved
bool checkNumCars();//checking that there is less then 5 cars
void reserveCar();//to reserve or unreserve a car
void viewAllCars();//method to view either all cars or cars that aren't already reserved
void sellCar();//remove a car from the list
void viewCar();//view a specific car
void insuranceQuote();
void saveToFile(FILE *);//save cars to binary file
void getFromFile(FILE *);//retrieve cars from binary file






void inputCar() {//method to create a car, will also add that car to the list and check if it is unique
	char reg[8], make[15], model[15], colour[10];
	int previousOwners, reserveAmt;
	bool reserved;
	bool checker;
	struct LinearNode *aNode;
	struct car* element;
	aNode = (struct LinearNode*)malloc(sizeof(struct LinearNode)); //create space for  the node
	element = (struct car*)malloc(sizeof(struct car));//create space for the car element
	

		do//do while loop for checking if the registation is correct
		{
			printf("Input the car reg : ");
			scanf("%s", reg);
			checker = checkReg(reg);
		} while (!checker);//end do while
		strcpy(element->reg, reg);

		printf("Input the car make : ");//make
		scanf("%s", make);
		strcpy(element->make, make);//end make

		printf("Input the %s model : ", make);//model
		scanf("%s", model);
		strcpy(element->model, model);//end model

		printf("Input the %s %s colour: ", make, model);//colour
		scanf("%s", colour);
		strcpy(element->colour, colour);//end colour


		do {//do while to check the num of previous owners is correct
			previousOwners = 0;
			printf("Input the number of previous owners for reg %s : ", reg);
			scanf("%d", &previousOwners);
		} while (previousOwners < 0 || previousOwners > 3);//end do while
		element->previousOwners = previousOwners;//end previous owners

		element->reserved = false;//ensuring the reserved is set to false

		aNode->next = NULL;//making the element ahead of this one = NULL
		aNode->element = element;//linking the car and the linked node

		//add node to end of the list
		if (isEmpty())
		{
			front = aNode;
			last = aNode;
		}
		else {
			last->next = aNode;
			last = aNode;
		} //end else

}

void viewAllCars() {
	int menuOption;
	struct LinearNode *current;
	if (isEmpty())//display that there are no cars in the linked list
		printf("Error - there are no nodes in the list\n");
	else {//otherwise give user option to view all cars or just those that are unreserved
		printf("Please click 1 to view all cars\nOr click 2 to view unreserved cars");
		scanf("%d", &menuOption);
		switch (menuOption) {//start switch for viewing cars
		case 1:
		current = front;
			while (current != NULL) {//while to loop through linked list and display all
				printf("Reg is %s\nMake : %s\nModel : %s\nColour : %s\nNum of previous owners : %d\n", current->element->reg, current->element->make, current->element->model, current->element->colour, current->element->previousOwners);
				if (isReserved(current))
					printf("This car is reserved\n");
				else
					printf("This car is not reserved\n");
				current = current->next;
			}//end while
		break;
		 case 2:
		   current = front;
			while (current != NULL) {//while to loop through linked list and display all cars that are not reserved
				if(current->element->reserved == true)//checking each car to be reserved or not
					printf("Reg is %s\nMake : %s\nModel : %s\nColour : %s\nNum of previous owners : %d\n", current->element->reg, current->element->make, current->element->model, current->element->colour, current->element->previousOwners);
				current = current->next;
			}//end while
			break;
		 default:
			break;
		 }	
	 }//end switch
} 

void sellCar() {
	char registration[8];
	printf("Please enter the reg you wish to sell : \n");
	scanf("%s", registration);
	int count = 0;//counter for how many times the do while loop has done and therefore where the element is in the list
	struct LinearNode *current;
	struct LinearNode *middleElm;
	current = front;
	middleElm = front;
	
		while (current != NULL) {//while loop to go through the linked list


			if (strcmp(registration, current->element->reg) == 0) {//checking if the reg matches the inputted one
				
				if (current->element->reserved == true) {//checking then if the car is reserved and therefore if it can be sold
					printf("This car has been reserved with a reserve amount of %d and will now be sold", current->element->reserveAmt);
					if (count == 0) {//if car is at front of list
						front = front->next;
					}//end if
					else if (current->next == NULL) {//if car is at the end
						
						for (int i = 1; i < count; i++) {//getting to the element before the correct one
							middleElm = middleElm->next;
						}//end for
						middleElm->next = NULL;//making the next element = NULL
						last = middleElm;
						
					}//end else if
					else {//else if the car is somewhere in the middle
						
						for (int i = 1; i < count; i++)//get to the element before the correct one
						{
							middleElm = middleElm->next;
						}
						middleElm->next = middleElm->next->next;//skip over the correct element hence making it non existant
					
					}//end else

				}//end if
				else {//displaying a message incase the car has not been reserved
					printf("This car has not been reserved and therefore cannot be sold\n");
				}
			}
			
			count++;
			current = current->next;


		}//end while

}//end sell car

void reserveCar() {
	char registration[8];
	printf("Please input the reg of the car to be reserved/unreserved : \n");
	scanf("%s", registration);
	struct LinearNode* current;
	current = front;
	
	
	while (current != NULL) {//loop linkedlist
		
		if (strcmp(registration, current->element->reg) == 0) {//if reg found
				printf("Match found\n");
				if (current->element->reserved == false) {//if the car isnt reserved
					current->element->reserved = true;//set it to be reserved
					int reserveAmt;
					do {//do while the reserve amount isn't correct
						printf("Enter the reserve amount : \n");
						scanf("%d", &reserveAmt);
					} while (reserveAmt < 500 || reserveAmt > 1500);//end do while
					current->element->reserveAmt = reserveAmt;
					printf("Reserve amount set to %d\n", current->element->reserveAmt);
				}//end if
				else {//else if the car is reserved
					current->element->reserved = false;//set it to not reserved
					current->element->reserveAmt = 0;//set the reserve amount back to  0
					printf("Car has been unreserved and reserve amount reset\n");
				}//end else

			
		}//end if
		current = current->next;
	}//end while
}//end reserveCar

void viewCar(){
	char registration[8];
	printf("Please input the reg of the car to be viewed : \n");
	scanf("%s", registration);
	struct LinearNode* current;
	current = front;


	while (current != NULL) {//loop linked list

		if (strcmp(registration, current->element->reg) == 0) {//if reg found display it
			printf("Reg is %s\nMake : %s\nModel : %s\nColour : %s\nNum of previous owners : %d\n", current->element->reg, current->element->make, current->element->model, current->element->colour, current->element->previousOwners);
			if (isReserved(current))
				printf("This car is reserved\n");
			else
				printf("This car is not reserved\n");
		}//end if
		current = current->next;

	}//end while
}//end view car

void insuranceQuote() {
	char registration[8];//to hold the reg being input
	int age = 0;//age of the user
	int quote;//quote price
	printf("Please input the reg of the car that you wish to get an insurance quote on : \n");
	scanf("%s", registration);
	struct LinearNode* current;
	current = front;
	int menuOption = 0;//option for the end menu options


	while (current != NULL) {//while to go through the linkedlist

		if (strcmp(registration, current->element->reg) == 0) {//if the reg is found
			if (!isReserved(current)) {//if the car is not reserved
				int firstTwo = atoi(registration);//parse the first pieces to numbers and stops when it encounters a letter
				while (age < 17 || age > 100) {//while the age is outside acceptable limits
					printf("Please enter your age : \n");
					scanf("%d", &age);
				}//end while
				if (age <= 50)
					quote = (50 - age) * (20 - firstTwo) * 10;//taking the persons age away from 50 i.e the younger the higher the number, then multiplying that by the age of the car times 10
				else
					quote = (age - 50) * (20 - firstTwo) * 10;//doing basically the same, just taking the age away from 50 instead
				printf("Your insurance quote is : %d\n click 1 if you would like to reserve this car\nOr 2 if you wish to exit\n", quote);
				scanf("%d", &menuOption);
				switch (menuOption) {//start switch
				case 1:
					reserveCar();
					break;
				default:
					break;
				}//end switch
			}
			else//else if the car is reserved
				printf("Sorry, this car is reserved and therefore you cannot get an insurance quote.\n");
		}//end if

		current = current->next;

	}//end while
}//end insurance quote

void menu() {
	int menuOption;
	do {
		printf("Option 1 : Add a new car to the showroom\nOption 2: Sell a car from the showroom\nOption 3 : Reserve/Unreserve a car in the showroom\nOption 4 : View all cars in the showroom\nOption 5 : View a specific car in showroom\nOption 6 : Get an insurance quote on a car\nOption 7 : Exit\n");

		printf("Enter the menu option number you wish to select :\n");
		scanf("%d", &menuOption);
		switch (menuOption) {
		case 0:
		case 1:
			if (checkNumCars())//Checking if there are already more then 5 cars in the system
				inputCar();//method to create a car, will also add that car to the list and check if it is unique
			else
				printf("Max num of cars in system");
			break;
		case 2:
		    sellCar();
			break;
		case 3:
			reserveCar();
			break;
		case 4:
			viewAllCars();
			break;
		case 5:
			viewCar();
			break;
		case 6:
			insuranceQuote();
		case 7:
			break;
		default:
			printf("Default value");

		}
	} while (menuOption != 7);

}
bool isEmpty() {//checking if the list is empty by seeing if the front element has a value
	if (front == NULL)
		return true;
	else
		return false;
}
bool isReserved(struct LinearNode *current) {//method to check if a car has been reserved or not
	if (current->element->reserved == true)
		return true;
	else
		return false;
}

bool checkReg(char reg[8]) {//checks if the car data is proper
	bool numbers = false;//a boolean to ensure the data in the first 2 numbers is correct
	bool correct = false;//a boolean to ensure the data in the 2nd position of the array is correct
	int firstTwo = atoi(reg);//parse the first pieces to numbers and stops when it encounters a letter
	if (firstTwo <= 19 && firstTwo >= 9)//check if those numbers are between the guidelines
		numbers = true;
	else
		numbers = false;
	char place = reg[2];
	if (reg[2] == 'd' || reg[2] == 'D')
		correct = true;
	else
		correct = false;

	if (numbers == true && correct == true)
		return true;
	else
		return false;

}

bool checkNumCars() {//checking that there is 5 or less cars by looping the linked list and adding to a counter
	struct LinearNode* current;
	int count = 0;
	bool okCars = true;
	current = front;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	if (count > 5)
		okCars = false;
	return okCars;
}
struct LinearNode *otherNode;

void getFromFile(FILE* fp) {
	struct car *anElement;
	struct LinearNode *current;
	printf("Retriving students from file...\n");

	anElement = (struct car *)malloc(sizeof(struct car));//crete space for element

	while (fread(anElement, sizeof(struct car), 1, fp) != NULL) {//read each element

		current = (struct LinearNode *)malloc(sizeof(struct LinearNode));//create space for node

		current->element = anElement;//join the element and node

		current->next = NULL;//set next to null

		if (isEmpty())//same if empty as the inputCar() method
		{
			front = current;
			last = current;
		}
		else {
			last->next = current;
			last = current;
		}

		anElement = (struct car *)malloc(sizeof(struct car));//create space for next element
	}
	fclose(fp);//close file

}

void saveToFile(FILE* fp) {
	struct LinearNode* current;
	current = front;
	fp = fopen("cars.dat", "wb");//open file
	while (current != NULL) {//loop linkedList
		fwrite(current->element, sizeof(struct car), 1, fp);//write the element into the file
		current = current->next;
	}//end while
	fclose(fp);//close file
}//end saveToFile

void main() {
	FILE *fp;
	int i;
	

	if ((fp = fopen("cars.dat", "rb")) != NULL) {//check if file exists
		getFromFile(fp);
	}

	menu();//menu exits with option 7
	saveToFile(fp);
	printf("System Exited");

	


	getchar(); //this stops screen disapearing
	getchar();

}//end main




