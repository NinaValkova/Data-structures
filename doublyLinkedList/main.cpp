#include <iostream>
#include "doublyLinkedList.h"

int main()
{
    DLList<int> list;

    list+=1;
    list+=2;
    list+=3;
    list+=3;
    list+=3;
    list+=3;
    list+=3;

    std::cout << list << std::endl;

    DLList<int>::Iterator it = list.begin();
    while ((it != list.end()))
    {
        std::cout << *it << " ";
        ++it;
    }
    
    std::cout << std::endl;
    int count = DLList<int>::count(&list, 3);
    std::cout << count << std::endl;

    std::cout << std::endl;
    DLList<int>::reverse(&list);

    std::cout << list << std::endl;
}