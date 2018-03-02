//---------------------------------------------------------------------
//File:  stack.h
//Description:  stack<char> linked list header file
//---------------------------------------------------------------------

#ifndef stack_h
#define stack_h

#include <iostream>
#include <string>
#include <cassert>


using namespace std;

class Node
{
public:
	char symbol;
	Node *next;
};

class Stack
{
public:
	Stack();
	Stack(const string & s);
	~Stack();
	char Top() const;
	int Count();
	bool Empty() const { return top == 0; }
	void Pop();
	void Push(const char & key);
	void PopAll();
	void Print();
	void operator+(const Stack & B);
	friend ostream & operator<<(ostream & out, const Stack & obj);

private:
	Node * top;
};

#endif