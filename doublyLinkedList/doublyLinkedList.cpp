#ifndef __DLLIST_CPP_
#define __DLLIST_CPP_

#include "doublyLinkedList.h"
#include <exception>

template <class T>
DLList<T>::DLList() : first(nullptr), last(nullptr)
{
}

template <class T>
DLList<T>::DLList(const DLList<T> &other)
{
    copy(other);
}

template <class T>
DLList<T>::~DLList()
{
    node *crr = first, *temp;

    while (crr != nullptr)
    {
        temp = crr;
        crr = crr->next;
        delete temp;
    }
}

template <class T>
void DLList<T>::clear()
{
    DLList<T>::node *crr = first, *temp;

    while (crr != nullptr)
    {
        temp = crr;
        crr = crr->next;
        delete temp;
    }

    first = last = nullptr;
}

template <class T>
DLList<T> &DLList<T>::operator=(const DLList<T> &other)
{
    if (this != &other)
    {
        clear();
        copy(other);
    }

    return *this;
}

template <class T>
DLList<T> DLList<T>::operator+(const T &x) const
{
    DLList<T> result(*this);
    result += x;
    return result;
}

template <class T>
DLList<T> &DLList<T>::operator+=(const T &x)
{
    DLList<T>::node *crr = new node{x, nullptr, last};

    if (last != nullptr)
    {
        last->next = crr;
    }
    else
    {
        first = crr;
    }

    last = crr;
    return *this;
}

template <class T>
void DLList<T>::copy(const DLList<T> &other)
{
    first = new DLList<T>::node{other.first->data, nullptr, nullptr};

    DLList<T>::node *crr = first;
    DLList<T>::node *temp = other.first->next;

    while (temp != nullptr)
    {
        crr->next = new node{temp->data, nullptr, crr};

        temp = temp->next;
        crr = crr->next;
    }

    last = crr;
}

template <class T>
std::ostream &operator<<(std::ostream &out, const DLList<T> &list)
{
    typename DLList<T>::node *crr = list.first;

    while (crr != nullptr)
    {
        out << crr->data << " ";
        crr = crr->next;
    }

    return out;
}

template <class T>
T &DLList<T>::Iterator::operator*()
{
    if (current == nullptr)
    {
        throw std::out_of_range("Null iterator");
    }
    return current->data;
}

template <class T>
typename DLList<T>::Iterator &DLList<T>::Iterator::operator++()
{
    if (current == nullptr)
    {
        throw std::out_of_range("Null iterator");
    }

    current = current->next;
    return *this;
}

template <class T>
typename DLList<T>::Iterator &DLList<T>::Iterator::operator--()
{
    if (current == nullptr)
    {
        throw std::out_of_range("Null iterator");
    }

    current = current->prev;
    return *this;
}

template <class T>
bool DLList<T>::Iterator::operator!=(const Iterator &it)
{
    return current != it.current;
}

template <class T>
bool DLList<T>::Iterator::operator==(const Iterator& it)
{
    return current == it.current;
}

template <class T>
DLList<T>::Iterator::Iterator(node *_current) : current(_current) {}

template <class T>
typename DLList<T>::Iterator DLList<T>::begin()
{
    return DLList<T>::Iterator(first);
}

template <class T>
typename DLList<T>::Iterator DLList<T>::end()
{
    return DLList<T>::Iterator(nullptr);
}

template <class T>
int DLList<T>::count(DLList<T> *l, int x)
{
    int count = 0;

    DLList<T>::node *crr = l->first;
    while (crr != nullptr)
    {
        if (crr->data == x)
        {
            count++;
        }
        crr = crr->next;
    }

    return count;
}

template <class T>
int DLList<T>::count2(DLList<T> *l, int x)
{
    int count = 0;

    for (auto it = l->begin(); it != l->end(); ++it)
    {
        if (*it == x)
        {
            count++;
        }
    }

    return count;
}

template <class T>
void DLList<T>::reverse(DLList<T> *l)
{
    // empty list
    if (l->first == nullptr)
    {
        return;
    }

    DLList<T>::node *crr = l->first;
    DLList<T>::node *temp = nullptr;

    while (crr != nullptr)
    {
        temp = crr->next;
        crr->next = crr->prev;
        crr->prev = temp;

        crr = temp;
    }

    // Swap first and last pointers of the list
    temp = l->first;
    l->first = l->last;
    l->last = temp;
}


template <class T>
void DLList<T>::reverse2(DLList<T>* l)
{
    // empty list
    if (l->first == nullptr)
    {
         return; 
    }

   Iterator left = l->begin();
   Iterator right = Iterator(l->last); 

    for (; left != right && !(++Iterator(left) == right); ++left, --right)
    {
        std::swap(*left, *right);
    }

}


#endif