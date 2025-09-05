#include <iostream>
#include "stackloader.h"

int main()
{
	Stack<char> stack;

	StackLoader stackLoader(stack);
	stackLoader.loadStack(1);
	stack.print();

	return 0;
}
