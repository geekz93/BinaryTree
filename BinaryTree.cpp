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
		_root->insert_value(elem, _root);
}


//root->_lchild: address or value?
template<typename valType>
void BTnode<valType>::
insert_value(valType &elem, BTnode *root)
{
	if (elem == _val)
    {
        _cnt++;
        return;
    }

	else
	if (elem < _val)
	{
		if (_lchild)
			root->insert_value(elem, _lchild);
		else
			_lchild = new BTnode(elem);
	}
	else
	{
		if (_rchild)
			root->insert_value(elem, _rchild);
		else
			_rchild = new BTnode(elem);
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

//在成员函数中直接使用变量或者函数实际是 this->val或者 this->fun()
//如果指定了 pointer->val 或者 pointer->fun() 则this指针会相应发生改变
//因此如果想要改变 this 指针就需要使用 pointer->

template <typename elemType>
void BinaryTree<elemType>::
remove(elemType elem)
{
    //使用remove_root(elem) 和 使用 _root->remove_root(elem) 的区别
    if( elem == _root->_val)
        remove_root(elem);
        //_root->remove_root(elem);//由于BTnode类中没有remove_root,因此会报错
    else
    {
        //先进行查找，<, >, ==
        //找到后执行移除操作（能否调用remove_root?）
        _root->remove_value(elem, _root);
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
    if(_root->_rchild)//_rchild在BTnode类中定义的，因此需要使用->
    {
        _root= _root->_rchild;
        lchild_leaf(pre_root->_lchild, _root);
    }

    else
        _root= _root->_lchild;

    delete pre_root;//

}

template<typename valType>
void BTnode<valType>::
remove_value(valType &elem, BTnode *&prev )
{
    //形参2的类型就是BTnode，this指针存储的是BTnode类型的地址
    if(elem < _val)
    {
        if(_lchild)
            prev->remove_value(elem, _lchild);
        else return;
    }

    else if(elem > _val)
    {
        if(_rchild)
            prev->remove_value(elem, _rchild);
        else return;
    }

    else //find
    {
        if(_rchild)
        {
            prev = _rchild;
            BinaryTree<valType>::lchild_leaf(_lchild, prev);
        }

        else
            prev = _lchild;

        delete this;

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
