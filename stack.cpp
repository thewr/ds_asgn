//---------------------------------------------------------------------
//File:  stack.cpp
//Description:  stack<char> linked list compiler file
//---------------------------------------------------------------------

#include "stack.h"

//---------------------------------------------------------------------
// Default Constructor
//---------------------------------------------------------------------
Stack::Stack() 
{
	cout << "Default Constructor Evoked!\n";
	top = 0;
}

//---------------------------------------------------------------------
// Explicit Value Constructor
//---------------------------------------------------------------------
Stack::Stack(const string & s)
{
	cout << "Explicit Value Constructor Evoked!" << endl;
	if (s.length() == 0)
	{
		top = 0;
		return;
	}

	top = new Node;
	Node *p = top;

	int i = s.length()-1;
	while (i != 0)
	{
		p->symbol = s[i--];
		p->next = new Node;
		p = p->next;
	}
	p->symbol = s[i];
	p->next = 0;
}

//---------------------------------------------------------------------
// Deconstructor
//---------------------------------------------------------------------
Stack::~Stack()
{
	cout << "Destructor Evoked!\n";
	while (top != 0)
	{
		Node *p = top;
		top;
		top = top->next;
		delete p;
	}
	PopAll();
}

//---------------------------------------------------------------------
// Returns top of stack.
//---------------------------------------------------------------------
char Stack::Top() const
{
	if (top != 0)
	{
		return top->symbol;
	}
	else
	{
		return -1;
		cerr << "Stack Empty" << endl;
	}
}

//---------------------------------------------------------------------
// Pushes a character onto top of stack.
//---------------------------------------------------------------------
void Stack::Push(const char & key) 
{
	Node *p = new Node;
	p->next = 0;
	p->symbol = key;

	if (top == 0)
	{
		top = p;
	}
	else
	{
		p->next = top;
		top = p;
	}
}

//---------------------------------------------------------------------
// Removes whats on top of stack.
//---------------------------------------------------------------------
void Stack::Pop()
{
	if (Empty())
	{
		cout << "Stack is empty cannot remove top" << endl;
	}
	else
	{
		Node * oldtop = top;
		top = top->next;
		delete oldtop;
	}
}

//----------------------------------------------------------------------
// returns how many items are in stack
//----------------------------------------------------------------------
int Stack::Count()
{
	if (top == 0)
	{
		return 0;  // if first node isn't utilized return length of 0.
	}
	else
	{
		Node *p = top;
		int count = 0;

		while (p != 0)  // traverse nodes until out of scope
		{
			count++;
			p = p -> next;  
		}
		return count;
	}	
}

//---------------------------------------------------------------------
// Removes all of stack contents.
//---------------------------------------------------------------------
void Stack::PopAll() 
{
	while (!Empty())
		Pop();
}

//---------------------------------------------------------------------
// Prints stack contents.
//---------------------------------------------------------------------
void Stack::Print()
{
	Node *p = top;
	cout << "Stack" << endl;
	while (p != 0) // while not inside terminated node 
	{
		cout << p->symbol << endl;
		p = p->next;
	}
	cout << endl << endl;
}

//---------------------------------------------------------------------
// Overide operator<< to print stack contents.
//---------------------------------------------------------------------
ostream & operator<<(ostream & out, const Stack & obj)
{
	Node *p = obj.top;

	while(p != 0)
	{
		out << p -> symbol << endl;
		p = p->next;
	}
	return out;
}

//---------------------------------------------------------------------
// Overator operator+ to add contents of stack B on top of stack A.
//---------------------------------------------------------------------
void Stack::operator+(const Stack & B)
{
	Node *p = B.top;  // point to front of string B

	while (p != 0) {
		Push(p->symbol);  // insert behind string A
		p = p->next;   // go to next till done
	}
}