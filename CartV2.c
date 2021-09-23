/* CartV2.c by Joe Thompson 9 / 18 / 21 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main (void)
{
	bool backpackPromo = false;    // boolean to check if backpack promo coupon will be added on line 118
  const float tierOne = .05f, tierTwo = .075f, tierThree = .105f, tierFour = .155f, tierFive = .175f;   	// float constants for discount tiers
	const float pencilPrice = .02f, notebookPrice = .89f, backpackPrice = 39.99f;		                 				// float constants for base price of items

	int pencils = 0, notebooks = 0, backpacks = 0, cartItems = 0;		// variables for user input
	float pencilTotal, notebookTotal, backpackTotal, cartTotal, discountRate, cartDiscount, cartAfterDisc;	  	// uninitialized floats for item totals to be displayed

	printf("\n\nJayhawk Enterprises Shopping Cart Calculator by Joe Thompson\n\n");

	/*
		The if statements on lines 27, 35, and 43 all
		make a call to the function checkQuantity, comments
		for this function can be found on line 126.
	*/

	printf("How many pencils would you like to order?   ");		// prompting the user for input using printf function
	scanf("%d", &pencils);  																	//  capturing the user's input with the scanf function

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

	if (backpacks > 4)  // applies the promo if user selects 5 or more backpacks
	{
		backpackPromo = true;
	}

	cartItems = pencils + notebooks + backpacks;
  /*
		if-else chain working in descending order to
		determine which tier discount to apply to The
		current order based on total cart items,
		default case will be tierOne.
	*/
	if (cartItems > 100)
	{
		discountRate = tierFive;
	}
	else if (cartItems > 80)
	{
		discountRate = tierFour;
	}
	else if (cartItems > 50)
	{
		discountRate = tierThree;
	}
	else if (cartItems > 20)
	{
		discountRate = tierTwo;
	}
	else
	{
		discountRate = tierOne;
	}
	/*
		Lines 87 - 89 use typecasting
		1: we should never make the compiler work harder than it has to
		2: as a programmer I want to know how my data is interacting
		   with each other, not leaving it up to the compiler to decided
		   what happens
	*/
	pencilTotal = (float) pencils * pencilPrice;
	notebookTotal = (float) notebooks * notebookPrice;
	backpackTotal = (float) backpacks * backpackPrice;
	cartTotal = pencilTotal + notebookTotal + backpackTotal;

  cartDiscount = discountRate * cartTotal; 											 // calculating the initial discount
	cartDiscount = (int) (cartDiscount * 100.0f + 0.5f) / 100.0f;  // rounding the above calculation to two decimal positions
	cartAfterDisc = cartTotal - cartDiscount;                      // applying discount to current cart total

	printf("\n\n\nYour Itemized Receipt");

	// lines 99 - 101 use a - in the conversion specifier to display left justification
	printf("\n\nNumber of Pencils  (0-100)  %-d\n", pencils);
	printf("Number of Notebooks (0-20)  %-d\n", notebooks);
	printf("Number of Backpacks (0-10)  %-d\n\n", backpacks);

	printf("Number of Items in Shopping Cart:%7d\n\n", cartItems);

	// lines 106 - 114 make use of the minimum field width and precision options of the conversion specifiers
	printf("Amount Owed for Pencils:\t $%6.2f", pencilTotal);
	printf("\nAmount Owed for Notebooks:\t $%6.2f", notebookTotal);
	printf("\nAmount Owed for Backpacks:\t $%6.2f\n", backpackTotal);

	printf("\nAmount Owed before Discount:\t $%6.2f\n", cartTotal);
  printf("Discount Rate: %4.3f\n", discountRate);
	printf("Discount Amount:\t        -$%6.2f\n", cartDiscount);

	printf("\nTotal Amount Owed:\t\t $%6.2f\n\n", cartAfterDisc);

	if (backpackPromo)
	{
		printf("*****Bring this receipt with you next time you visit us to receive $5.00 off your future purchase*****\n\n");
	}
	printf("Thank you for shopping at Jayhawk Enterprises!\n\n\n");

	return 0;
}


/*
	checkQuantity has two parameters, input from the user, and
	a max value of available items.  Using a while loop on line 135 I
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
