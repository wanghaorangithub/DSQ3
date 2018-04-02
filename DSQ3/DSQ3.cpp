// DSQ3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "expresstree.h"
#include<string>
#include"exchange.h"
#include <stack>
using namespace std;
double get_double(string mid, int left, int right);
string get_string(string pre, int left, int right);
string get_string(string pre, int position);
BinaryTreeNode<string>* pre_to_tree(string pre);
BinaryTreeNode<string>* mid_to_tree(string mid);
BinaryTreeNode<string>* pst_to_tree(string pst);

double get_double(string mid, int left, int right)
{
	int nfloat = right;
	double dtemp = 0;
	for (int i = left; i <= right; i++)
	{
		if (mid[i] == ' ')continue;
		if (mid[i] == '.') {
			nfloat = i;
			continue;
		}
		dtemp = 10 * dtemp + mid[i] - '0';
	}//���itemp
	nfloat = right - nfloat;
	while (nfloat-- != 0)dtemp /= 10.0;//���ʵ�ʴ�С
	return dtemp;
}
string get_string(string pre, int left, int right) {
	string result;
	for (int i = left; i <= right; i++) {
		result.push_back(pre[i]);
	}
	return result;
}
string get_string(string pre, int position) {
	string result;
	result.push_back(pre[position]);
	return result;
}
BinaryTreeNode<string>* pre_to_tree(string pre) {
	int left, right;
	stack<BinaryTreeNode<string>*>stack;
	for (int pos = pre.size() - 1; pos > -1; pos--)
	{
		if (isNumber(pre[pos]))
		{
			right = pos;//���ִ��Ҷ˵�
			while (isNumber(pre[pos]) || pre[pos] == '.')pos--;
			left = pos + 1;//���ִ���˵�
			BinaryTreeNode<string> *child = new BinaryTreeNode<string>();
			child->setValue(get_string(pre, left, right));
			child->setLeftChild(nullptr);
			child->setRightChild(nullptr);
			stack.push(child);
		}//���ֽڵ���ջ
		if (isOperator(pre[pos]))
		{
			BinaryTreeNode<string> *root = new BinaryTreeNode<string>();
			root->setValue(get_string(pre, pos));
			root->setLeftChild(stack.top());
			stack.pop();
			root->setRightChild(stack.top());
			stack.pop();
			stack.push(root);
		}//�����������ջ���Ҳ�������������
	}
	return stack.top();
}
BinaryTreeNode<string>* mid_to_tree(string mid) {
	string post;
	post = infixToPostfix(mid);
	return pst_to_tree(post);
}
BinaryTreeNode<string>* pst_to_tree(string pst) {
	int left, right;//���ִ������ұ߽�
	stack<BinaryTreeNode<string>*> stack;//���ʽ��ջ
	for (int pos = 0; pos < pst.size(); pos++) {
		if (isNumber(pst[pos])) {
			BinaryTreeNode<string>*child = new BinaryTreeNode<string>();
			child->setValue("0");
			left = pos;
			while (isNumber(pst[++pos]));
			right = pos - 1;
			child->setValue(get_string(pst, left, right));
			child->setRightChild(nullptr);
			child->setLeftChild(nullptr);
			stack.push(child);
		}//�����֣��������ֽڵ�
		if (isOperator(pst[pos])) {
			BinaryTreeNode<string> *root = new BinaryTreeNode<string>();
			root->setValue(get_string(pst, pos));
			root->setRightChild(stack.top());
			stack.pop();
			root->setLeftChild(stack.top());
			stack.pop();
			stack.push(root);
		}//�����������ջ����������ѹ��ջ
	}
	return stack.top();//����ջ��ָ���ַ
}//��׺����
int main()
{
	string str;
	cout << "������׺���ʽ:";
	getline(cin, str);
	BinaryTreeNode<string> *root = nullptr;
	root = mid_to_tree(str);
	ExpressTree<string> *midTree = new ExpressTree<string>(root);
	midTree->preOrder(root);
	cout << endl;
	midTree->inOrder(root);
	cout << endl;
	midTree->postOrder(root);
	cout << endl;

	cout << "����ǰ׺���ʽ:";
	getline(cin, str);
	root = pre_to_tree(str);
	ExpressTree<string> *expressTree = new ExpressTree<string>(root);
	expressTree->preOrder(root);
	cout << endl;
	expressTree->inOrder(root);
	cout << endl;
	expressTree->postOrder(root);
	cout << endl;

	cout << "�����׺���ʽ:";
	getline(cin, str);
	root = pst_to_tree(str);
	ExpressTree<string> *postTree = new ExpressTree<string>(root);
	postTree->preOrder(root);
	cout << endl;
	postTree->inOrder(root);
	cout << endl;
	postTree->postOrder(root);
	cout << endl;
	return 0;
}

