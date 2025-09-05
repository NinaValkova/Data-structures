#ifndef __BINARYSEARCHTREE_H_
#define __BINARYSEARCHTREE_H_
#include <iostream>

template <class T>
class BinarySearchTree
{
private:
    struct node
    {
        T data;
        node *left;
        node *right;
    };

    node *root;

    void DFS(std::ostream &, node *);

    void clear(node *);

public:
    BinarySearchTree();
    ~BinarySearchTree();

    /*
     void insertOrdered(const T&);
     void insertOrdered(const T&, node*&);
    */

    void print(std::ostream &);

    class Position
    {
    public:
        Position(node *&);
        Position left() const;
        Position right() const;
        bool empty() const;
        void set(const T &);
        T get() const;

    private:
        //
        node *&current;
    };

    // позиция на корен на дърво
    Position rootPosition();

    bool search(const T &);

    bool search(const T &, typename BinarySearchTree<T>::Position current);
};

#include "binarySearchTree.cpp"

#endif
