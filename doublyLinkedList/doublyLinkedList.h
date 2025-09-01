#ifndef __DLLIST_H_
#define __DLLIST_H_

#include <iostream>

template <class T>
class DLList
{
    public:
    DLList();
    DLList(const DLList<T>&);
    ~DLList();

    DLList<T>& operator = (const DLList<T>&);
    DLList<T> operator + (const T&) const;
    DLList<T>& operator += (const T&);

    // функция, която преброява колко пъти елемента x се среща в списъка 
    static int count(DLList<T>* l, int x);

    // функция, която преброява колко пъти елемента x се среща в списъка - втори вариант
    static int count2(DLList<T>* l, int x);

    // функция, която обръща реда на елементите
    static void reverse( DLList<T>* l);

    // функция, която обръща реда на елементите - втори вариант
    static void reverse2( DLList<T>* l);

    private:
    struct box
    {
        T data;
        box *next, *prev;
    };

    box *first;
    box *last;


    public:
       class Iterator
    {
        public:
        Iterator(box* _current);

        T& operator *();
        Iterator& operator ++();
        Iterator& operator --();
        bool operator!= (const Iterator&);
        bool operator== (const Iterator&); 

        private:
        box* current;
    };

    Iterator begin();
    Iterator end();

    private:
    template<class E>
    friend std::ostream& operator<< (std::ostream&, const DLList<E>&);

    void copy(const DLList<T>&);
    void clear();
};

template<class T>
std::ostream& operator<< (std::ostream&, const DLList<T>&);


#include "doublyLinkedList.cpp"

#endif