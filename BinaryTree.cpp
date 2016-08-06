#include "BinaryTree.h"
//wrong function format, the return should place
//in the front of class
template<typename elemType>
void BinaryTree<elemType>::
insert(elemType elem)
{
	if (!_root)
		_root = new BTnode<elemType>(elem);
	else
		insert_value(elem, _root);
}

template<typename elemType>
void BinaryTree<elemType>::
insert_value(elemType elem, BTnode<elemType> *root)
{
	if (elem == root->_val)
		return;
}