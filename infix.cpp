//---------------------------------------------------------------------
//File:  infix.cpp
//Description:  infix compiler file
//---------------------------------------------------------------------

#include "infix.h"
#include "stack.h"
#include <cassert>

// CONSTANTS
const string BLANK = " ";
const string OPENP = "(";
const string CLOSEP = ")";

//---------------------------------------------------------------------
// returns true if current token is an operator; otherwise false.
//---------------------------------------------------------------------
bool Is_Operator(char arg)
{
	if (arg == '*' || arg == '/' || arg == '+' || arg == '-')
		return 1;
	else
		return 0;
}
//---------------------------------------------------------------------
// returns true if current token is an operand; otherwise false.
//---------------------------------------------------------------------
bool Is_Operand(char arg)
{
	if (arg >= 'a' && arg <= 'z')
		return 1;
	if (arg >= 'A' && arg <= 'Z')
		return 1;
	return -1;
}
//---------------------------------------------------------------------
// removes blank space from input string.
//---------------------------------------------------------------------
string removeSpaces(string input)
{
	for (int i = input.length() - 1; i >= 0;--i) {
		if (input[i] == ' ')
			input.erase(i, 1);
	}
	return input;
}
//---------------------------------------------------------------------
// Converts RPN expression to INFIX expression.
//---------------------------------------------------------------------
string INFIX(string RPN)
{
	RPN = removeSpaces(RPN);				 //remove spaces from input
	
	Stack operands;							 //make Stack object for operands
	
	int capacity = 2;						 //max subexpressions to be stored
	int count = 0;							 //number of subexpressions inside str_arr
	string* str_arr = new string[capacity];  //allocate memory for str_arr string to store subexpressions;
	string aStr, bStr;						 //name of subexpressions to be used with an operator;
	
	char a, b;								 //single character type to be used with subexpressions; operator
	int len = RPN.size();					 //get length of input
	char x;								     //current token
	for (int i = 0; i < len; i++)
	{
		// load token
		x = RPN[i];

		if (Is_Operand(x) && len==1)
		{
			str_arr[count].append(OPENP + x + CLOSEP);
		}
		else
		{
			if (!operands.Empty() && Is_Operator(x))
			{
				// pop two operands off the stack
				if(operands.Count()<=capacity)
				{
					a = operands.Top();
					operands.Pop();
					b = operands.Top();
					operands.Pop();
					str_arr[count].append(OPENP + a + x + b + CLOSEP);
					count++;
				}			
			}
			else if (operands.Empty() && Is_Operator(x))
			{
				if (count < capacity)
				{
					aStr = str_arr[count - 1];
					bStr = str_arr[count];
					str_arr[count].append(OPENP + aStr + x + bStr + CLOSEP);
				}
				else
				{
					aStr = str_arr[0];
					bStr = str_arr[1];
					count = 0;
					str_arr[count] = "";
					str_arr[count].append(OPENP + aStr + x + bStr + CLOSEP);
					cout << str_arr[0];
				}
			}
			else if (Is_Operand(x))
			{

				if (operands.Count() < 2)
				{
					operands.Push(x);
				}
				else if (operands.Count())
				{
					cerr << "Too Many Operands!" << endl;
					break;
				}
			}
		}
	}	
	cout << endl;
	string infixstr;
	if (count != 0)
	{
		for (int i = 0; i < count;i++)
		{
			infixstr = infixstr + str_arr[i];
		}
	}
	else
	{
		infixstr = str_arr[count];

	}
	return infixstr;
}



