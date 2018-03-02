//---------------------------------------------------------------------
//File:  stack.h
//Description:  infix program library 
//---------------------------------------------------------------------

#ifndef infix_h
#define infix_h

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

string INFIX(string exp);
bool Is_Operator(char arg);
bool Is_Operand(char arg);
string removeSpaces(string input);

#endif
