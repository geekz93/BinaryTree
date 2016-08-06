
template<typename elemType>
//err claim: class BinaryTree<elemType>;
class BinaryTree;

template<typename valType>
class BTnode{
	friend class BinaryTree<valType>;
public:
//how to define construction function?
	BTnode(valType val);
	void insert(valType elem);
	void remove();
	void insert_value(valType elem, BTnode *root);

private:
	valType _val;
	int _cnt;
	BTnode *_lchild;
	BTnode *_rchild;

};

/*need add valType*/
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
	
private:
	BTnode<elemType> *_root;
};

