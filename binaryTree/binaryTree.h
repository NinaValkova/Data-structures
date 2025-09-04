#ifndef __BINARYTREE_H_
#define __BINARYTREE_H_
#include <iostream>

template<class T>
class BinaryTree
{
    private:
    struct node
    {
        T data;
        node* left;
        node* right;
    };

    node* root;

    void DFS(std::ostream&, node*);

    //намира по следа указател към елемента в дървото 
    node* locate(const char*) const;

    bool memberhelper(const T&, node*) const;

    T sum(node*) const;
    T findBiggest(node*) const;
    T countNodes(node*) const;
    T treeHeight(node*) const;
    T sumEven(node*) const;
    T sumOdd(node*) const;

    void clear(node*);
 
    public:
    BinaryTree();
    ~BinaryTree();

    //добавяне на елемент на позиция която няма елемент
    void add(const T& element, const char* trace);

    void print(std::ostream&);

    //намиране на елемент на позиция
    T operator[](const char*) const;
    void set(const T& x, const char* trace);

    //проверка за принадлежност на елемент на дърво
    bool member(const T&) const;

    // сума на елементи на дърво
    T sum() const;

    // функция, която намира най-голям елемент в дървото
    T findBiggest() const;

    // функция, която намира броя елементи в дървото
    T countNodes() const;

    // функция, която намира височина на дървото
    T treeHeight() const;

    // функция, която намира сумата на четните стойности от върховете на дадено двоично дърво
    T sumEven() const;

    // функция, която намира сумата на нечетните стойности от върховете на дадено двоично дърво
    T sumOdd() const;
};

#include "binaryTree.cpp"

#endif
