#ifndef _BINARYTREE_H
#define _BINARYTREE_H


template<typename elemType>
class BinaryTree;
//err claim: class BinaryTree<elemType>;

template<typename valType>
class BTnode{
	friend class BinaryTree<valType>;
public:
//how to define construction function?
	BTnode(valType val);

private:
	valType _val;
	int _cnt;
	BTnode *_lchild;
	BTnode *_rchild;

};

/*need add valType*/
//when use a template, must we always need a <T> behind BTnode?
template<typename valType>
BTnode<valType>::
BTnode(valType val) :_val(val)
{
	_cnt = 1;
	_lchild = 0;
	_rchild = 0;
}

//how to create a root node?
//ans: when insert a value the root node will be created
//what the construction do?
//ans: assignment 0 to _root
template <typename elemType>
class BinaryTree{
	friend class BTnode<elemType>;
public:
	BinaryTree() :_root(0){};
	//void insert(elemType elem){}
	void insert(elemType elem);
	void remove( elemType elem);//search value from root, so just one parameter
	void insert_value(elemType elem, BTnode<elemType> *root);
	void display();
	void lchild_leaf(BTnode<elemType> *branch, BTnode<elemType> *subtree);//merge left node to right subtree's left button

private:
	BTnode<elemType> *_root;
	void preorder(BTnode<elemType>* root);
	void remove_root(elemType elem);
	void remove_value(elemType elem, BTnode<elemType> *&prev);

};

#endif
