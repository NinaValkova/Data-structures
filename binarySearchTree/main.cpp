#include <iostream>

#include "binarySearchTree.h"
#include "binarySearchTreeFunctions.h"

int main()
{
    BinarySearchTree<int> to;

    insertOrdered(10, to.rootPosition());
    insertOrdered(20, to.rootPosition());
    insertOrdered(30, to.rootPosition());
    insertOrdered(40, to.rootPosition());
    insertOrdered(50, to.rootPosition());
    insertOrdered(60, to.rootPosition());

    to.print(std::cout);

    bool temp = to.search(40);
    if (temp)
    {
        std::cout << "Element is found" << std::endl;
    }
    else
    {
        std::cout << "Element not found" << std::endl;
    }

    return 0;
}