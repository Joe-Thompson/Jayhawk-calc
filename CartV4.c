/* CartV4.c by Joe Thompson 9 / 18 / 21 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
//TODO: getItemQuan() needs error proofing for char input from userclear
int getItemQuan(int max, char *item)
{
	int numItems = 0;

	do
    {
        printf("\n\nNumber of %s (0-%d)   ", item, max);		// prompting the user for input using printf function
	    scanf("%d", &numItems);		//  capturing the user's input with the scanf function

        if (numItems < 0 || numItems > max)		// if statement to ensure user input is within range for item
        {
            printf("\a\tOut of range! Enter 0 through %d", max);
        }

    } while (numItems < 0 || numItems >max);

	return numItems;
}

int main(void)
{
	bool backpackPromo = false, storeOpen = true;		// boolean to check if backpack promo coupon will be added on line 132
    const float tierOne = .05f, tierTwo = .075f, tierThree = .105f, tierFour = .155f, tierFive = .175f;		// float constants for discount tiers
	const float pencilPrice = .02f, notebookPrice = .89f, backpackPrice = 39.99f;		// float constants for base price of items

	char processAnother = 'n';
	int pencils = 0, notebooks = 0, backpacks = 0, cartItems = 0, totalCust = 0;		// int's for user input and number of customers orders
	float pencilTotal, notebookTotal, backpackTotal, cartTotal, discountRate, cartDiscount, cartAfterDisc, totalCustAmt = 0;		// floats for item totals to be displayed

	printf("\n\nJayhawk Enterprises Shopping Cart Calculator by Joe Thompson\n\n");

    /*
        CODE REFACTORED FROM V2
        The function checkQuantity has been removed, the logic 
        to ensure user input is within range is now handled by
        three seperate do-while loops.  
    */

   	while (storeOpen)
	   {

		if (totalCust > 1)
		{
			backpackPromo = false;
			pencils = 0, notebooks = 0, backpacks = 0, cartItems = 0;
			pencilTotal = 0, notebookTotal = 0, backpackTotal = 0, cartTotal = 0, cartDiscount = 0, cartAfterDisc = 0;
		}

	   
		pencils = getItemQuan(100, "Pencils");
		notebooks = getItemQuan(20, "Notebooks");
		backpacks = getItemQuan(10, "Backpacks");


		if (backpacks > 5)  // applies the promo if user purchases more than five backpacks
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

		pencilTotal = (float) pencils * pencilPrice;
		notebookTotal = (float) notebooks * notebookPrice;
		backpackTotal = (float) backpacks * backpackPrice;
		cartTotal = pencilTotal + notebookTotal + backpackTotal;

		cartDiscount = discountRate * cartTotal;		// calculating the initial discount
		cartDiscount = (int) (cartDiscount * 100.0f + 0.5f) / 100.0f;		// rounding the above calculation to two decimal positions
		cartAfterDisc = cartTotal - cartDiscount;		// applying discount to current cart total

		printf("\n\n\nYour Itemized Receipt");

		// lines 115 - 117 use a - in the conversion specifier to display left justification
		printf("\n\nNumber of Pencils  (0-100)  %-d\n", pencils);
		printf("Number of Notebooks (0-20)  %-d\n", notebooks);
		printf("Number of Backpacks (0-10)  %-d\n\n", backpacks);

		printf("Number of Items in Shopping Cart:%7d\n\n", cartItems);

		// lines 123 - 130 make use of the minimum field width and precision options of the conversion specifiers
		printf("Amount Owed for Pencils:\t $%6.2f", pencilTotal);
		printf("\nAmount Owed for Notebooks:\t $%6.2f", notebookTotal);
		printf("\nAmount Owed for Backpacks:\t $%6.2f\n", backpackTotal);

		printf("\nAmount Owed before Discount:\t $%6.2f\n", cartTotal);
		printf("Discount Rate: %.3f\n", discountRate);
		printf("Discount Amount:\t        -$%6.2f\n", cartDiscount);

		printf("\nTotal Amount Owed:\t\t $%6.2f\n\n", cartAfterDisc);

		if (backpackPromo)
		{
			printf("*****Bring this receipt with you next time you visit us to receive $5.00 off your future purchase*****\n\n");
		}

	
	//TOcd mDO:testing logic with below if else for correct handling of data. 
		printf("Would you like to process another customer (y or n): ");
		scanf("%s", &processAnother);


		if (toupper(processAnother) == 'N')
		{
			totalCustAmt += cartAfterDisc;
			totalCust++;
			storeOpen = false;
			
		}
		else if (toupper(processAnother) == 'Y')
		{
			totalCustAmt += cartAfterDisc;
			totalCust++;
		}
		else 
		{
			totalCustAmt += cartAfterDisc;
			totalCust++;

			while (toupper(processAnother) != 'Y' && toupper(processAnother) != 'N')
			{
			printf("\n\aOpps! %c is an invalid entry, try again (y or n): ", processAnother);
			scanf("%s", &processAnother);
			} 
			
			if (toupper(processAnother) == 'N')
			{
				storeOpen = false;
			}
		}
	   }

	
	

	
	/*
		Lines 103 - 105 use typecasting
		1: we should never make the compiler work harder than it has to
		2: as a programmer I want to know how my data is interacting
		   with each other, not leaving it up to the compiler to decided
		   what happens
	*/
	printf("\n\nNumber of Customers Processed:\t%d", totalCust);
    printf("\nGrand Total of all Total Amounts Owed:\t$%7.2f", totalCustAmt);
	printf("\n\nThank you for shopping at Jayhawk Enterprises!\n\n\n");

	return 0;
}



