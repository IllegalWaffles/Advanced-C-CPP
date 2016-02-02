#include <stdio.h>
#define MAX_DIGITS 16
/*

Kuba Gasiorowski, kgasiorowski, 109776237, kuba.gasiorowski@sbu.edu

Used compiler TDM-GCC 4.9.2

Program which reads a 16-digit long integer number, and
then determines if it is a valid credit card number.

*/

//See each function definition for more detailed comments
int addEvenDigits(char[MAX_DIGITS]);
int addOddDigits(char[MAX_DIGITS]);
int adjustCharacterValue(int);

int main()
{
	
	char cardToTest[MAX_DIGITS];
	
	printf("Enter a %d digit credit card number: ", MAX_DIGITS);
	
	int i;
	for(i = 0; i < MAX_DIGITS; i++){
	
		cardToTest[i] = getchar();
	
	}
	
	int evenSum = addEvenDigits(cardToTest);
	int oddSum = addOddDigits(cardToTest);
	
	printf("Even sum:%d\nOdd sum:%d\n", evenSum, oddSum);
	
	int totalSum = evenSum + oddSum;
	
	printf("Total sum: %d\n", totalSum);
	
	printf("Remainer when divided by 10: %d\n", totalSum%10);
	printf("Valid card:");
	
	if(totalSum%10 == 0)
		printf("YES");
	else
		printf("NO");
	
	return 0;
	
}

//Adds the even-indexed digits of the credit card number to verify.
int addEvenDigits(char number[MAX_DIGITS])
{
	
	int i, j, currentInt, sum=0;
	char temp[2];
	
	//For each digit
	for(i = 0; i < MAX_DIGITS; i+=2)
	{
	
		//The current number we're working with is the digit doubled
		currentInt = adjustCharacterValue(number[i]) * 2;
		
		//If the current number is greater than or equal to ten
		if(currentInt >= 10)
		{
			
			//Cast the number to a string
			sprintf(temp, "%d", currentInt);
			
			//Parse each digit and add to the sum
			for(j = 0; j < 2; j++){
				
				sum+=adjustCharacterValue(temp[j]);
			
			}
			
		}
		else
			//Otherwise add to digit to the sum
			sum += currentInt;
	
	}
	
	//Return the sum of the doubled even-indexed numbers
	return sum;
	
}

//Adds the odd-indexed digits of the credit card number to verify.
int addOddDigits(char number[MAX_DIGITS])
{
	
	int i, currentInt, sum=0;
	
	//For each digit, add it to the sum
	for(i = 1; i < MAX_DIGITS; i+=2){
	
		sum += adjustCharacterValue(number[i]);

	}
	
	//Return the sum of the odd-indexed numbers
	return sum;
	
}

//Adjusts the character value for a given input.
int adjustCharacterValue(int a)
{
	
	return a-'0';
	
}

