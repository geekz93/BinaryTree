#include "BinaryTree.h"
#include "BinaryTree.cpp"
int main()
{
	BinaryTree<int> ibt;
	
	ibt.insert(2);
	ibt.insert(3);
	ibt.insert(1);
	ibt.display();
	return 0;
}