#ifndef __DLLIST_CPP_
#define __DLLIST_CPP_

#include "doublyLinkedList.h"
#include <exception>

template <class T>
DLList<T>::DLList() 
{
    //елемента е един и сочи себе си
    first.next = &first;
    first.prev = &first;
}

template <class T>
DLList<T>::DLList(const DLList<T> &other)
{
    copy(other);
}

template <class T>
DLList<T>::~DLList()
{
    box *crr = first, *temp;

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
    DLList<T>::box *crr = first.next, *temp;

    while (crr != &first)
    {
        temp = crr;
        crr = crr->next;
        delete temp;
    }

    first.next = &first;
    first.prev = &first;
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
    first->next = new DLList<T>::box{x, first.next, &first};

    if(first.prev == &first)
    {
        first.prev = first.next;
    }

    return *this;
}

template <class T>
void DLList<T>::copy(const DLList<T> &other)
{
    first = new DLList<T>::box{other.first->data, nullptr, nullptr};

    DLList<T>::box *crr = first;
    DLList<T>::box *temp = other.first->next;

    while (temp != nullptr)
    {
        crr->next = new box{temp->data, nullptr, crr};

        temp = temp->next;
        crr = crr->next;
    }

}

template <class T>
std::ostream &operator<<(std::ostream &out, const DLList<T> &list)
{
    typename DLList<T>::box *crr = list.first.next;

    while (crr != &list.first)
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
DLList<T>::Iterator::Iterator(box *_current) : current(_current) {}

template <class T>
typename DLList<T>::Iterator DLList<T>::begin()
{
    return DLList<T>::Iterator(first.next);
}

template <class T>
typename DLList<T>::Iterator DLList<T>::end()
{
    return DLList<T>::Iterator(&first);
}


#endif
