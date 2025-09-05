#ifndef __STACK_CPP_
#define __STACK_CPP_

#include <iostream>

#include "stack.h"

template <class T>
Stack<T>::Stack()
{
    first = nullptr;
    last = nullptr;
}

template <class T>
Stack<T>::~Stack()
{
    Stack<T>::Node *current = first;
    Stack<T>::Node *temp = nullptr;

    while (current != nullptr)
    {
        temp = current;
        current = current->next;
        delete temp;
    }
}

template <class T>
void Stack<T>::push(T data)
{
    if (last == nullptr)
    {
        last = new Stack<T>::Node();
        last->data = data;
        last->prev = nullptr;
        last->next = nullptr;

        first = last;
    }
    else
    {
        Stack<T>::Node *node = new Stack<T>::Node();
        node->data = data;
        node->prev = last;
        node->next = nullptr;

        last->next = node;

        last = node;
    }
}

template <class T>
T Stack<T>::pop()
{
    T data = last->data;
    Stack<T>::Node *node = last;

    last = last->prev;
    if (last)
    {
        last->next = nullptr;
    }

    delete node;

    return data;
}

template <class T>
void Stack<T>::print()
{
    Stack<T>::Node *current = first;

    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
}

#endif