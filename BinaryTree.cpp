#include "BinaryTree.h"
#include<iostream>
using namespace std;

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


//root->_lchild: address or value?
template<typename elemType>
void BinaryTree<elemType>::
insert_value(elemType elem, BTnode<elemType> *root)
{
	if (elem == root->_val)
		return;
	else
	if (elem < root->_val)
	{
		if (root->_lchild)
			insert_value(elem, root->_lchild);
		else
			root->_lchild = new BTnode<elemType>(elem);
	}
	else
	{
		if (root->_rchild)
			insert_value(elem, root->_rchild);
		else
			root->_rchild = new BTnode<elemType>(elem);
	}
}

template <typename elemType>
void BinaryTree<elemType>::
display()
{
	preorder(_root);
	cout << endl;
}

template <typename elemType>
void BinaryTree<elemType>::
preorder(BTnode<elemType>* root)
{
	if (root)
	{
		//cout << root->_val;
		cout << root->_val << ' ';
		if(root->_lchild) preorder(root->_lchild);
		if(root->_rchild) preorder(root->_rchild);
	}
	
}