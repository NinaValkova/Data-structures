#ifndef __BINARYTREE_CPP_
#define __BINARYTREE_CPP_

#include "binaryTree.h"

#include <cassert>

template <class T>
BinaryTree<T>::BinaryTree() : root(nullptr)
{
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
    clear(root);
}

template <class T>
void BinaryTree<T>::clear(BinaryTree<T>::node* current)
{
    if(current == nullptr)
    {
        return;
    }

    clear(current->left);
    clear(current->right);

    delete current;
}

template <class T>
void BinaryTree<T>::add(const T &element, const char *trace)
{
    if (root == nullptr || trace[0] == 0)
    {
        assert(root == nullptr || trace[0] == 0);
        root = new BinaryTree<T>::node{element, nullptr, nullptr};
        return;
    }

    BinaryTree<T>::node *current = root;

    while (current != nullptr && trace[1] != 0)
    {
        assert(trace[0] == 'L' || trace[0] == 'R');

        if (trace[0] == 'L')
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }

        ++trace;
    }

    assert(current != nullptr);
    assert(trace[0] == 'L' || trace[0] == 'R');

    if (trace[0] == 'L')
    {
        assert(current->left == nullptr);
        current->left = new node{element, nullptr, nullptr};
    }
    else
    {
        assert(current->right == nullptr);
        current->right = new node{element, nullptr, nullptr};
    }
}

template <class T>
void BinaryTree<T>::print(std::ostream &out)
{
    DFS(out, root);
    out << std::endl;
}

template <class T>
void BinaryTree<T>::DFS(std::ostream &out, BinaryTree<T>::node *current)
{
    if (current == nullptr)
    {
        return;
    }

    DFS(out, current->left);
    out << current->data << " ";
    DFS(out, current->right);
}

template <class T>
T BinaryTree<T>::operator[](const char *trace) const
{
    return locate(trace)->data;
}

template <class T>
void BinaryTree<T>::set(const T &x, const char *trace)
{
    locate(trace)->data = x;
}

template <class T>
typename BinaryTree<T>::node *BinaryTree<T>::locate(const char *trace) const
{
    assert(root != nullptr);

    // the character at the current pointer position - trace[0] <=> *(trace + 0)
    if (trace[0] == 0)
    {
        return root;
    }

    BinaryTree<T>::node *current = root;
    while (current != nullptr && trace[0] != 0)
    {
        assert(trace[0] == 'L' || trace[0] == 'R');

        if (trace[0] == 'L')
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }

        // after ++trace, the base address of trace is no longer addres of index 0 —but it’s addres of index 1
        ++trace;
    }

    assert(current != nullptr);

    return current;
}


template <class T>
bool BinaryTree<T>::member(const T&x) const
{
    return memberhelper(x, root);
}

template <class T>
bool BinaryTree<T>::memberhelper(const T& x, node* current) const
{
    if(current == nullptr)
    {
        return false;
    }

    if(current->data == x)
    {
        return true;
    }

    if(memberhelper(x, current->left))
    {
        return true;
    }

    if(memberhelper(x, current->right))
    {
        return true;
    }

    return false;
    /*
    return current != nullptr &&
           (x== current->data) ||
           memberhelper(x, current->left) || 
           memberhelper(x, current->right);
    */
}

template <class T>
T BinaryTree<T>::sum() const
{
    return sum(root);
}

template <class T>
T BinaryTree<T>::sum(BinaryTree<T>::node *current) const
{
    if(current == nullptr)
    {
        return 0;
    }

    return current->data 
           + sum(current->left)
           + sum(current->right);
}

template <class T>
T BinaryTree<T>::findBiggest() const
{
    return findBiggest(root);
}

template <class T>
T BinaryTree<T>::findBiggest(BinaryTree<T>::node *current) const
{
    if(current == nullptr)
    {
        return 0;
    }


    T leftMax  = findBiggest(current->left);
    T rightMax = findBiggest(current->right);

    T maxElement = current->data;

    if(leftMax > maxElement)
    {
        maxElement = leftMax;
    }

    if(rightMax > maxElement)
    {
        maxElement = rightMax;
    }
    
    return maxElement;
}

template <class T>
T BinaryTree<T>::countNodes() const
{
    return countNodes(root);
}

template <class T>
T BinaryTree<T>::countNodes(BinaryTree<T>::node *current) const
{
    static unsigned int count = 0;

    if(current == nullptr)
    {
        return 0;
    }

    countNodes(current->left);
    countNodes(current->right);

    ++count;

    return count;
}

template <class T>
T BinaryTree<T>::treeHeight() const
{
   return treeHeight(root);
}

template <class T>
T BinaryTree<T>::treeHeight(BinaryTree<T>::node *current) const
{

   if(current == nullptr)
    {
        return 0;
    }


    T leftCount = 1 + treeHeight(current->left);
    
    T rightCount = 1 + treeHeight(current->right);
    

    if(leftCount > rightCount)
    {
        return leftCount;
    }
    else 
    {
        return rightCount;
    }
    
    return leftCount;
}

template <class T>
T BinaryTree<T>::sumEven() const
{
   return sumEven(root);
}

template <class T>
T BinaryTree<T>::sumOdd() const
{
   return sumOdd(root);
}

template <class T>
T BinaryTree<T>::sumEven(BinaryTree<T>::node *current) const
{
     if(current == nullptr)
    {
        return 0;
    }

    if((current->data) % 2 == 1)  // odd value

    {
        // skip adding current->data , but continue with recursion - make recursive calls for the left and right children.
          return sumEven(current->left)
                + sumEven(current->right);
    }

    return current->data
           + sumEven(current->left)
           + sumEven(current->right);
}

template <class T>
T BinaryTree<T>::sumOdd(BinaryTree<T>::node *current) const
{
    if(current == nullptr)
    {
        return 0;
    }

    if((current->data) % 2 == 0)
    {
          return sumOdd(current->left)
                + sumOdd(current->right);
    }

    return current->data
           + sumOdd(current->left)
           + sumOdd(current->right);
}

#endif
