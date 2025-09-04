#include <iostream>

#include "binaryTree.h"

int main()
{
	BinaryTree<int> binaryTree;

	binaryTree.add(10, "");
	binaryTree.add(20, "L");
	binaryTree.add(30, "R");
	binaryTree.add(40, "LL");
	binaryTree.add(50, "LLL");
	binaryTree.add(60, "LLR");

	binaryTree.print(std::cout);

	std::cout << binaryTree["R"] << std::endl;

	std::cout << binaryTree.member(30) << std::endl;
	binaryTree.set(31, "R");
	std::cout << binaryTree.member(30) << std::endl;

	binaryTree.print(std::cout);


	std::cout << "sum: " << binaryTree.sum() << std::endl;

	std::cout << "biggest element: " << binaryTree.findBiggest() << std::endl;

	std::cout << "count of nodes: " << binaryTree.countNodes() << std::endl;

	std::cout << "height of the tree: " << binaryTree.treeHeight() << std::endl;

	std::cout << "sum even: "<< binaryTree.sumEven() << std::endl;

	std::cout << "sum odd: "<< binaryTree.sumOdd() << std::endl;


    return 0;
}