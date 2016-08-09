#include "BinaryTree.h"
#include "BinaryTree.cpp"
int main()
{
	BinaryTree<int> ibt;
	ibt.insert(23);
	ibt.insert(3);
	ibt.insert(1);
	ibt.insert(10);
	ibt.insert(33);
	ibt.insert(26);
	ibt.insert(45);
	ibt.display();
	ibt.remove(3);
	ibt.display();

	return 0;
}
