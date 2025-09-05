#ifndef __STACKLOADER_H_
#define __STACKLOADER_H_

#include "stack.h"

class StackLoader
{
private:
    Stack<char> &stack;

public:
    StackLoader(Stack<char> &stack) : stack(stack) {}

    void loadStack();
    void loadStack(int upper);
};

#endif
