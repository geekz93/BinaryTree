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
insert_value(elemType &elem, BTnode<elemType> *root)
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

template <typename elemType>
void BinaryTree<elemType>::
remove(elemType elem)
{
    if( elem == _root->_val)
        remove_root(elem);
    else
    {
        //先进行查找，<, >, ==
        //找到后执行移除操作（能否调用remove_root?）
        remove_value(elem, _root);
    }

}

template<typename elemType>
void BinaryTree<elemType>::
remove_root(elemType &elem)
{
    //由于_root将会被更新，因此需要临时变量来存储原来
    //的根节点的地址，用于delete和对原_lchild进行操作
    BTnode<elemType> *pre_root;
    pre_root = _root;
    if(_root->_rchild)
    {
        _root= _root->_rchild;
        lchild_leaf(pre_root->_lchild, _root);
    }

    else
        _root= _root->_lchild;

    delete pre_root;//

}

template<typename elemType>
void BinaryTree<elemType>::
remove_value(elemType &elem, BTnode<elemType> *&prev )
{
    if(elem < prev->_val)
    {
        if(prev->_lchild)
            remove_value(elem, prev->_lchild);
        else return;
    }

    else if(elem > prev->_val)
    {
        if(prev->_rchild)
            remove_value(elem, prev->_rchild);
        else return;
    }

    else //find
    {
        BTnode<elemType> *tmp;
        tmp=prev;
        if(prev->_rchild)
        {
            prev = prev->_rchild;
            lchild_leaf(tmp->_lchild, prev);
        }

        else
            prev = prev->_lchild;

        delete tmp;

    }

}

template<typename elemType>
void BinaryTree<elemType>::
lchild_leaf(BTnode<elemType> *leaf, BTnode<elemType> *subtree)
{
    while(subtree->_lchild)
    {
         subtree = subtree->_lchild;
    }
    subtree->_lchild = leaf;
}
