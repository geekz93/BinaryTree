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
	cout << "traverse the tree: ";
	ibt.display();
	ibt.remove(3);
	ibt.remove(33);
	cout << "remove 3 and 33: ";
    ibt.display();
	return 0;
}
