/* CartV1.c by Joe Thompson 9 / 3 / 21 */

#include <stdio.h>

int main (void)
{
	
	const float pencilPrice = .02f, notebookPrice = .89f, backpackPrice = 39.99f;		// float constants for base price of items
	
	int pencils = 0, notebooks = 0, backpacks = 0, cartItems = 0;						// variables for user input
	float pencilTotal, notebookTotal, backpackTotal, cartTotal;							// uninitialized floats for item totals to be displayed
	
	printf("\n\nJayhawk Enterprises Shopping Cart Calculator by Joe Thompson\n\n");
	
	/*
		The if statements on lines 24, 32, and 40 all 
		make a call to the function checkQuantity, comments
		for this function can be found on line 79.
	*/
	
	printf("How many pencils would you like to order?   ");		// prompting the user for input using printf function
	scanf("%d", &pencils);  									//  capturing the user's input with the scanf function

	if (pencils < 0 || pencils > 100)
		{
			pencils = checkQuantity (pencils, 100);
		};
	
	printf("\nHow many notebooks would you like to order?   ");
	scanf("%d", &notebooks);

	if (notebooks < 0 || notebooks > 20)
		{
			notebooks = checkQuantity (notebooks, 20);
		};
	
	printf("\nHow many backpacks would you like to order?   ");
	scanf("%d", &backpacks);

	if (backpacks < 0 || backpacks > 10)
		{
			backpacks = checkQuantity (backpacks, 10);
		};
	
	cartItems = pencils + notebooks + backpacks;
	/*
		Lines 53 - 55 use typecasting
		1: we should never make the compiler work harder than it has to
		2: as a programmer I want to know how my data is interacting
		   with each other, not leaving it up to the compiler to decided 
		   what happens
	*/
	pencilTotal = (float) pencils * pencilPrice;
	notebookTotal = (float) notebooks * notebookPrice;
	backpackTotal = (float) backpacks * backpackPrice;
	cartTotal = pencilTotal + notebookTotal + backpackTotal;
	
	printf("\n\n\nYour Itemized Receipt");
	
	// lines 61 - 63 use a - in the conversion specifier to display left justification
	printf("\n\nNumber of Pencils  (0-100)  %-d\n", pencils);
	printf("Number of Notebooks (0-20)  %-d\n", notebooks);
	printf("Number of Backpacks (0-10)  %-d\n\n", backpacks);

	printf("Number of Items in Shopping Cart:%7d\n\n", cartItems);

	// lines 68 - 72 make use of the minimum field width and precision options of the conversion specifiers 
	printf("Amount Owed for Pencils:\t $%6.2f", pencilTotal);
	printf("\nAmount Owed for Notebooks:\t $%6.2f", notebookTotal);
	printf("\nAmount Owed for Backpacks:\t $%6.2f", backpackTotal);
	
	printf("\n\nTotal Amount Owed:\t\t $%6.2f\n\n", cartTotal);
	printf("Thank you for shopping at Jayhawk Enterprises!\n\n\n");
	
	return 0;
}


/*
	checkQuantity has two parameters, input from the user, and 
	a max value of available items.  Using a while loop on line 88 I
	alert the user of the problem and ask for a new input. The while
	loop will continue until the user's input is greater than -1
	and less than the passed in argument for maxAllowed
*/
int checkQuantity(int userInput,int maxAllowed)
{
	while (userInput < -1 || userInput > maxAllowed)
	{
		printf("\nOops! Looks like your're out of range (0 - %d)", maxAllowed);
		printf("\nPlease enter a new amount:   ");
		scanf("%d", &userInput);
		
	}
	
	return userInput;
}