#ifndef __TREEFUNC_CPP_
#define __TREEFUNC_CPP_

#include "binarySearchTree.h"

template <class T>
void insertOrdered(const T &x, typename BinarySearchTree<T>::Position current)
{
    if (current.empty())
    {
        current.set(x);
        return;
    }

    if (x <= current.get())
    {
        insertOrdered(x, current.left());
    }
    else
    {
        insertOrdered(x, current.right());
    }
}

#endif