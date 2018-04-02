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
		if (root == nullptr)return;           //�ݹ���ý�������  
		else
		{
			cout << root->value() << " ";            //���ʸ��ڵ�  
			preOrder(root->getLeftChild());      //ǰ��ݹ����������  
			preOrder(root->getRightChild());      //ǰ�����������  
		}
	}
	void inOrder(BinaryTreeNode<T>*root) {
		if (root == nullptr)return;           //�ݹ���ý�������  
		else
		{
			inOrder(root->getLeftChild());      //ǰ��ݹ����������  
			cout << root->value() << " ";            //���ʸ��ڵ�  
			inOrder(root->getRightChild());      //ǰ�����������  
		}
	}
	void postOrder(BinaryTreeNode<T>*root) {
		if (root == nullptr)return;           //�ݹ���ý�������  
		else {
			postOrder(root->getLeftChild());      //ǰ��ݹ����������  
			postOrder(root->getRightChild());      //ǰ�����������  
			cout << root->value() << " ";            //���ʸ��ڵ�  
		}
	}
	void deleteBinaryTree(BinaryTreeNode<T>*root) {
		if (root != NULL)
		{
			deleteBinaryTree (root->getLeftChild);//�ͷ�������  
			deleteBinaryTree(root->getRightChild);//�ͷ�������  
			delete root;
		}
	}
};
#endif //!BINARYTREE