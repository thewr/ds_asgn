//---------------------------------------------------------------------
//File:  infix_driver.cpp
//Description:  infix driver compiles full program
//Course: Date Structures and Algorithm Analysis (COP3530)
//Professor: Dr.Lofton Bullard
//Name: Ryan Thew; Z: 15156390
//Date: March 2nd, 2018
//Assignment 7:  infix
//Description:  Converts RPN expression to infix
//---------------------------------------------------------------------

#include <iostream>
#include "infix.h"
#include "stack.h"
#include <iomanip>

using namespace std;

int main()
{

	string postfix;
	int ch;

	do {
		string NAME = "MENU";
		int WIDTH = 80, LENGTH = NAME.length();
		cout << setfill('-') << setw(WIDTH/2-LENGTH/2) << '-' << NAME << setfill('-') << setw(WIDTH-LENGTH-WIDTH / 2 - LENGTH / 2) << '-' << endl;
		cout << "\t\t\t1) run infix.cpp" << endl;
		cout << "\t\t\t2) exit" << endl;

		cout << "\nEnter your choice:";
		cin >> ch;

		cin.ignore();  //ignore enter before getline
		cout << endl;

		while (cin.fail())  //force input to be only numeric
		{
			cout << "Invalid Entery" << endl;
			cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "\nEnter your choice:";
			cin >> ch;
		}

		switch (ch)
		{
		case 1:
			cout << "Enter Postfix: ";
			getline(cin, postfix);
			cout << "Infix: " << INFIX(postfix) << endl;
			break;
		case 2:
			cout << "Exiting Program!" << endl;
			exit(1);
		default:
			cout << "Not a valid choice" << endl;
		}
	} while (ch != 2);

	return 0;
}