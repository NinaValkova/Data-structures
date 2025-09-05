#include "stackloader.h"

void StackLoader::loadStack()
{
    const size_t ASCII = 97;
    for (size_t i = 0; i < 26; i++)
    {
        char letter = i + ASCII;
        this->stack.push(letter);
    }
}

void StackLoader::loadStack(int upper)
{
    size_t ASCII = (upper == 1) ? 65 : 97;
    for (size_t i = 0; i < 26; i++)
    {
        char letter = i + ASCII;
        this->stack.push(letter);
    }
}
