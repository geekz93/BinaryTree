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
	BTnode(valType &val);

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
BTnode(valType &val) :_val(val)
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
	void insert_value(elemType &elem, BTnode<elemType> *root);
	void display();
	void lchild_leaf(BTnode<elemType> *branch, BTnode<elemType> *subtree);//merge left node to right subtree's left button

private:
	BTnode<elemType> *_root;
	void preorder(BTnode<elemType>* root);
	void remove_root(elemType &elem);
	//使用 *&prev 的原因：
	//与使用 &a 作为函数形参的作用一样，使得在函数中对 a 的修改能够实际影响 a 的值
	//*&prev对比 &a可以发现，这是对指针型变量 prev 的引用，这样对 prev 的修改就能实际影响 prev 的值
	void remove_value(elemType &elem, BTnode<elemType> *&prev);

};

#endif
