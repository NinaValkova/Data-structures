#ifndef __STACK_H_
#define __STACK_H_

template <class T>
class Stack
{
private:
	struct Node
	{
		T data;
		Node *next;
		Node *prev;
	};

	Node *first;
	Node *last;

public:
	Stack();
	~Stack();

	void push(T data);
	T pop();

	void print();
};

#include "stack.cpp"

#endif
