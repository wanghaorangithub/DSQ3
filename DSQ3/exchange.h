#pragma once
#ifndef EXCHANGE
#define EXCHANGE
#include <iostream>
#include<string>
#include"mystack.h"
using namespace std;
bool isNumber(char ch);		//�ж��Ƿ�Ϊ���֣����򷵻�true
bool isOperator(char op);                         // �ж��Ƿ�Ϊ�����  
int getPriority(char op);                            // ����������ȼ�  
string infixToPostfix(string pre);    // ����׺���ʽת��Ϊ��׺���ʽ  
double readNumber(string str);            // �������ַ���ת�����Ӧ������  
double getPostfixValue(string post);                // �ɺ�׺���ʽ�ַ���������Ӧ����ֵ���ʽ��ֵ    

bool isNumber(char ch) {
	if (ch >= 48 && ch <= 57)
		return true;
	else
		return false;
}
bool isOperator(char op)
{
	switch (op)
	{
	case '+':
	case '-':
	case '*':
	case '/':
		return 1;
	default:
		return 0;
	}
}
int getPriority(char op) {
	switch (op) {
	case '#':
		return -1;
	case '(':
		return 0;
	case '+':
		return 1;
	case '-':
		return 1;
	case '*':
		return 2;
	case '/':
		return 2;
	default:
		return -1;
	}
}
string infixToPostfix(string pre) {
	int i = 0;
	string post;
	MyStack<char> stack;
	while (i < pre.length()) {
		if (isNumber(pre[i])) {// ��������ֱ��д���׺���ʽ  
			post.push_back(pre[i]);
		}
		else if (pre[i] == '(' || pre[i] == '��')   // �������������ñȽ�ֱ����ջ  
			stack.push(pre[i]);
		else if (pre[i] == ')' || pre[i] == '��')  // ���������Ž����Ӧ�����ź�Ĳ�������������ջ�еģ�ȫ��д���׺���ʽ  
		{
			while (stack.getTop() != '(' || stack.getTop() != '��')
			{
				post.push_back(stack.pop());
			}
			if (stack.isEmpty())
			{
				cout << "there is no '( ',eror equation";
				break;
			}
			else
				stack.pop(); // ����������ջ����׺���ʽ�в���С����  
		}
		else if (isOperator(pre[i]))
		{
			post.push_back(' ');; // �ÿո�ֿ�������
			while (!stack.isEmpty() && getPriority(pre[i]) <= getPriority(stack.getTop()))
			{
				// ��ǰ�Ĳ�����С�ڵ���ջ�������������ȼ�ʱ����ջ��������д�뵽��׺���ʽ���ظ��˹���  
				post.push_back(stack.pop());
			}
			stack.push(pre[i]); // ��ǰ���������ȼ�����ջ�������������ȼ������ò�������ջ  
		}
		i++;
	}
	while (!stack.isEmpty()) // �����еĲ����������׺���ʽ  
	{
		post.push_back(stack.pop());
	}
	return post;
}
double readNumber(string str) {
	int i = 0;
	double result = 0.0;
	while (isNumber(str[i]))
		result = result * 10 + (str[i++] - '0');
	return result;
}
double getPostfixValue(string post) {
	MyStack<double> stack;
	string number;
	int i = 0;
	double x = 0, y = 0;
	while (i < post.size())
	{
		if (isNumber(post[i]))
		{
			while (isNumber(post[i]))
			{
				number.push_back(post[i]);
				i++;
			}
			stack.push(readNumber(number));
		}
		if (post[i] == ' ')
			i++;
		else if (post[i] == '+')
		{
			y = stack.pop();
			x = stack.pop();
			stack.push(x + y);
			i++;
		}
		else if (post[i] == '-')
		{
			y = stack.pop();
			x = stack.pop();
			stack.push(x - y);
			i++;
		}
		else if (post[i] == '*')
		{
			y = stack.pop();
			x = stack.pop();
			stack.push(x *y);
			i++;
		}
		else if (post[i] == '/')
		{
			y = stack.pop();
			x = stack.pop();
			stack.push(x / y);
			i++;
		}
		number.clear();
	}
	return stack.getTop();
}

#endif //!EXCHANGE