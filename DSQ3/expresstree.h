#pragma once
#ifndef BINARYTREE
#define BINARYTREE
#include <iostream>
template <typename T> class ExpressTree;
template <typename T>
class BinaryTreeNode {
	friend class ExpressTree<T>;
private:
	T data;
	BinaryTreeNode<T> * leftChild;
	BinaryTreeNode<T> * rightChild;
public:
	BinaryTreeNode() {};
	BinaryTreeNode(T data) { this.data = data; }
	BinaryTreeNode<T> * getLeftChild() { return leftChild; }
	BinaryTreeNode<T> * getRightChild() { return rightChild; }
	T value() { return data; }
	void setLeftChild(BinaryTreeNode<T>* left) { leftChild = left; }
	void setRightChild(BinaryTreeNode<T>* right) { rightChild = right; }
	void setValue(T val) { data=val; }
};

template <typename T>
class ExpressTree {
private:
	BinaryTreeNode<T>*root;
public:
	ExpressTree() { root = nullptr; }
	ExpressTree(BinaryTreeNode<T>*root) { this->root = root; }
	~ExpressTree() { deleteBinaryTree(root); }
	BinaryTreeNode<T> *getRoot() { return root; }
	void preOrder(BinaryTreeNode<T>*root) {
		if (root == nullptr)return;           //递归调用结束条件  
		else
		{
			cout << root->value() << " ";            //访问根节点  
			preOrder(root->getLeftChild());      //前序递归访问左子树  
			preOrder(root->getRightChild());      //前序访问右子树  
		}
	}
	void inOrder(BinaryTreeNode<T>*root) {
		if (root == nullptr)return;           //递归调用结束条件  
		else
		{
			inOrder(root->getLeftChild());      //前序递归访问左子树  
			cout << root->value() << " ";            //访问根节点  
			inOrder(root->getRightChild());      //前序访问右子树  
		}
	}
	void postOrder(BinaryTreeNode<T>*root) {
		if (root == nullptr)return;           //递归调用结束条件  
		else {
			postOrder(root->getLeftChild());      //前序递归访问左子树  
			postOrder(root->getRightChild());      //前序访问右子树  
			cout << root->value() << " ";            //访问根节点  
		}
	}
	void deleteBinaryTree(BinaryTreeNode<T>*root) {
		if (root != NULL)
		{
			deleteBinaryTree (root->getLeftChild);//释放左子树  
			deleteBinaryTree(root->getRightChild);//释放右子树  
			delete root;
		}
	}
};
#endif //!BINARYTREE