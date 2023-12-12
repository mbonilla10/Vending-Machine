// This program simulates the payment section of a vending machine.
// The vending machine only dispenses sodas which are priced at $1.30

#include <iostream>
using namespace std;

// Create an enumeration data type called Money
enum class Money { nickel = 5, dime = 10, quarter = 25, dollar = 100 };

const int MAXSIZE = 26;
const int PRICE = 130;

// Prints price to the screen in the format: $X.XX
// price represents an amount of money, in pennies
void PrintPrice(int price);

// Takes user input (1, 2, 3, 4) and converts it to a Money type
Money ConvertToMoney(int x);

// Prints a word to the screen stating what the Money type is
void PrintMoney(Money x);

// Prints the coins to dispense, which add up to amount
// Note: This will never need to dispense a dollar
void DispenseChange(int amount);

int main()
{
	int amountLeft = PRICE;
	int entryAmount = 0;

	Money coinsInMachine[MAXSIZE];

	cout << "*** Vending Machine ***" << endl << endl;
	// displays price
	cout << "Deposit ";
	PrintPrice(PRICE);
	cout << " for a soda." << endl << endl;

	cout << "1: deposit nickel    2: deposit dime    3: deposit quarter    4: deposit dollar    5: cancel transaction" << endl;

	//Asks the user to continue entering money
	while (amountLeft > 0)
	{
		int input = 0;

		cout << "Enter: > ";

		cin >> input;
		
		//Checks to see if input is a valid
		if (input >= 1 && input <= 4)
		{
			amountLeft -= (int)ConvertToMoney(input);
			coinsInMachine[entryAmount] = ConvertToMoney(input);
			entryAmount += 1;
		}
		else if (input == 5)
		{
			cout << endl << "Transaction cancelled." << endl;
			if (amountLeft != PRICE)
			{
				cout << "Returning: " << endl << ">> ";
				
				for(int i = 0;  i < entryAmount; i++){
					PrintMoney(coinsInMachine[i]);
				}
				
			}
			return 0;
		}

		cout << endl << endl;
		
		//Checks to see if "Amount left to pay" needs to be displayed
		if (amountLeft > 0)
		{
			cout << "Amount left to pay: ";
			PrintPrice(amountLeft);
			cout << endl;
		}
	}

	cout << "Dispensing soda." << endl << endl;

	//Shows change returned if needed
	if (amountLeft < 0)
	{
		cout << "Change owed: ";
		PrintPrice(-amountLeft);
		cout << endl << "Returning:" << endl << ">>";

		DispenseChange(-amountLeft);
	}

	cout << endl;
	return 0;
}

//Displays money with dollar sign format and decimal places
void PrintPrice(int price)
{	
	int dollars = price / 100;
	int cents = price % 100;

	//Checks to see if an extra 0 is needed.
	if (cents >= 10)
	{
		cout << "$" << dollars << "." << cents;
	}
	else
	{
		cout << "$" << dollars << "." << "0" << cents;
	}

}

// Checks amount remaning and displays amounts
void DispenseChange(int amount)
{	
	int remainingAmount = amount;

	while (remainingAmount > 0)
	{
		if (remainingAmount >= 100)
		{
			cout << " dollar ";
			remainingAmount -= 100;
		}
		else if (remainingAmount >= 25)
		{
			cout << " quarter ";
			remainingAmount -= 25;
		}
		else if (remainingAmount >= 10)
		{
			cout << " dime ";
			remainingAmount -= 10;
		}
		else if (remainingAmount >= 5)
		{
			cout << " nickel ";
			remainingAmount -= 5;
		}
	}
	
}

Money ConvertToMoney(int x)
{
	//Checks money value and converts to Money enum.
	if (x == 1)
	{
		return Money::nickel;
	}
	else if (x == 2)
	{
		return Money::dime;
	}
	else if (x == 3)
	{
		return Money::quarter;
	}
	else if (x == 4)
	{
		return Money::dollar;
	}

	return Money::dollar;
}

void PrintMoney(Money x)
{
	//Checks money type and prints the name.
	if (x == Money::nickel) 
	{
		cout << "nickel  ";
	}
	if (x == Money::dime)
	{
		cout << "dime  ";
	} 
	if (x == Money::quarter)
	{
		cout << "quarter  ";
	}
	if (x == Money::dollar)
	{
		cout << "dollar  ";
	}
}