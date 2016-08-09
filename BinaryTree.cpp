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

//�ڳ�Ա������ֱ��ʹ�ñ������ߺ���ʵ���� this->val���� this->fun()
//���ָ���� pointer->val ���� pointer->fun() ��thisָ�����Ӧ�����ı�
//��������Ҫ�ı� this ָ�����Ҫʹ�� pointer->

template <typename elemType>
void BinaryTree<elemType>::
remove(elemType elem)
{
    //ʹ��remove_root(elem) �� ʹ�� _root->remove_root(elem) ������
    if( elem == _root->_val)
        remove_root(elem);
        //_root->remove_root(elem);//����BTnode����û��remove_root,��˻ᱨ��
    else
    {
        //�Ƚ��в��ң�<, >, ==
        //�ҵ���ִ���Ƴ��������ܷ����remove_root?��
        _root->remove_value(elem, _root);
    }

}

template<typename elemType>
void BinaryTree<elemType>::
remove_root(elemType &elem)
{
    //����_root���ᱻ���£������Ҫ��ʱ�������洢ԭ��
    //�ĸ��ڵ�ĵ�ַ������delete�Ͷ�ԭ_lchild���в���
    BTnode<elemType> *pre_root;
    pre_root = _root;
    if(_root->_rchild)//_rchild��BTnode���ж���ģ������Ҫʹ��->
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
    //�β�2�����;���BTnode��thisָ��洢����BTnode���͵ĵ�ַ
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
