#ifndef __BINARYSEARCHTREE_CPP_
#define __BINARYSEARCHTREE_CPP_

#include "binarySearchTree.h"

#include <cassert>

template <class T>
BinarySearchTree<T>::BinarySearchTree() : root(nullptr)
{
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
    clear(root);
}

template <class T>
void BinarySearchTree<T>::clear(BinarySearchTree<T>::node *current)
{
    if (current == nullptr)
    {
        return;
    }

    clear(current->left);
    clear(current->right);

    delete current;
}

template <class T>
void BinarySearchTree<T>::print(std::ostream &out)
{
    DFS(out, root);
    out << std::endl;
}

template <class T>
void BinarySearchTree<T>::DFS(std::ostream &out, BinarySearchTree<T>::node *current)
{
    if (current == nullptr)
    {
        return;
    }

    DFS(out, current->left);
    out << current->data << " ";
    DFS(out, current->right);
}

/*
template <class T>
void BinarySearchTree<T>::insertOrdered(const T& x)
{
    insertOrdered(x, root);
}

template <class T>
void BinarySearchTree<T>::insertOrdered(const T &x, node*& current)
{
    if(current == nullptr)
    {
        //създаване на ново листо, което го присвояваме на вече съществуващо дърво
        current = new node{x, nullptr, nullptr};
        return;
    }

    if(x <= current->data)
    {
        insertOrdered(x, current->left);
    }
    else
    {
        insertOrdered(x, current->right);
    }
}
*/

template <class T>
BinarySearchTree<T>::Position::Position(node *&_current) : current(_current)
{
}

template <class T>
typename BinarySearchTree<T>::Position BinarySearchTree<T>::Position::left() const
{
    // Position, който облича указател и свежда операците към операции с позиции вместо операции с указатели
    assert(current != nullptr);
    return Position(current->left);
}

template <class T>
typename BinarySearchTree<T>::Position BinarySearchTree<T>::Position::right() const
{
    assert(current != nullptr);
    return Position(current->right);
}

template <class T>
bool BinarySearchTree<T>::Position::empty() const
{
    return current == nullptr;
}

template <class T>
void BinarySearchTree<T>::Position::set(const T &x)
{
    if (current != nullptr)
    {
        current->data = x;
    }
    else
    {
        current = new typename BinarySearchTree<T>::node{x, nullptr, nullptr};
    }
}

template <class T>
T BinarySearchTree<T>::Position::get() const
{
    assert(current != nullptr);
    return current->data;
}

template <class T>
typename BinarySearchTree<T>::Position BinarySearchTree<T>::rootPosition()
{
    return BinarySearchTree<T>::Position(root);
}

template <class T>
bool BinarySearchTree<T>::search(const T &x)
{
    return search(x, BinarySearchTree<T>::rootPosition());
}

template <class T>
bool BinarySearchTree<T>::search(const T &x, typename BinarySearchTree<T>::Position current)
{
    if (current.empty())
    {
        return false;
    }

    if (x == current.get())
    {
        return true;
    }
    else if (x < current.get())
    {
        return search(x, current.left());
    }
    else
    {
        return search(x, current.right());
    }

    return false;
}

#endif
