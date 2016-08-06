#include "BinaryTree.h"
//wrong function format, the return should place
//in the front of class
template<typename valType>
void BTnode<valType>::
insert(valType elem)
{
	if (!_root)
		_root = new BTnode(elem);
	else
		insert_value(elem, _root);
}

template<typename valType>
void BTnode<valType>::
insert_value(valType elem, BTnode *root)
{
	if (elem == root->_val)
		return;
}