/* CartV2.c by Joe Thompson 9 / 18 / 21 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main (void)
{
	bool backpackPromo = false;    // boolean to check if backpack promo coupon will be added on line 118
    const float tierOne = .05f, tierTwo = .075f, tierThree = .105f, tierFour = .155f, tierFive = .175f;   	// float constants for discount tiers
	const float pencilPrice = .02f, notebookPrice = .89f, backpackPrice = 39.99f;		                 	// float constants for base price of items

	int pencils = 0, notebooks = 0, backpacks = 0, cartItems = 0;		// variables for user input
	float pencilTotal, notebookTotal, backpackTotal, cartTotal, discountRate, cartDiscount, cartAfterDisc;	 // uninitialized floats for item totals to be displayed

	printf("\n\nJayhawk Enterprises Shopping Cart Calculator by Joe Thompson\n\n");

    /*
        CODE REFACTORED FROM V2
        The function checkQuantity has been removed, the logic 
        to ensure user input is within range is now handled by
        three seperate do-while loops.  
    */

	do
    {
        printf("\n\nNumber of Pencils (0-100)   ");		// prompting the user for input using printf function
	    scanf("%d", &pencils);  						//  capturing the user's input with the scanf function

        if (pencils < 0 || pencils > 100)
        {
            printf("\a\tOut of range! Enter 0 through 100");
        }

    } while (pencils < 0 || pencils > 100);
    

	do
    {
        printf("\n\nNumber of Notebooks (0-20)   ");		
	    scanf("%d", &notebooks);  									

        if (notebooks < 0 || notebooks > 20)
        {
            printf("\a\tOut of range! Enter 0 through 20");
        }

    } while (notebooks < 0 || notebooks > 20);

	do
    {
        printf("\n\nNumber of Backpacks (0-10)   ");		
	    scanf("%d", &backpacks);  					
    			
        if (backpacks < 0 || backpacks > 10)
        {
            printf("\a\tOut of range! Enter 0 through 10");
        }

    } while (backpacks < 0 || backpacks > 10);

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
		Lines 101 - 103 use typecasting
		1: we should never make the compiler work harder than it has to
		2: as a programmer I want to know how my data is interacting
		   with each other, not leaving it up to the compiler to decided
		   what happens
	*/
	pencilTotal = (float) pencils * pencilPrice;
	notebookTotal = (float) notebooks * notebookPrice;
	backpackTotal = (float) backpacks * backpackPrice;
	cartTotal = pencilTotal + notebookTotal + backpackTotal;

    cartDiscount = discountRate * cartTotal; 						// calculating the initial discount
	cartDiscount = (int) (cartDiscount * 100.0f + 0.5f) / 100.0f;  // rounding the above calculation to two decimal positions
	cartAfterDisc = cartTotal - cartDiscount;                      // applying discount to current cart total

	printf("\n\n\nYour Itemized Receipt");

	// lines 113 - 115 use a - in the conversion specifier to display left justification
	printf("\n\nNumber of Pencils  (0-100)  %-d\n", pencils);
	printf("Number of Notebooks (0-20)  %-d\n", notebooks);
	printf("Number of Backpacks (0-10)  %-d\n\n", backpacks);

	printf("Number of Items in Shopping Cart:%7d\n\n", cartItems);

	// lines 120 - 128 make use of the minimum field width and precision options of the conversion specifiers
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

