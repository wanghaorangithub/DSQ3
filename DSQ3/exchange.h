#pragma once
#ifndef EXCHANGE
#define EXCHANGE
#include <iostream>
#include<string>
#include"mystack.h"
using namespace std;
bool isNumber(char ch);		//判断是否为数字，是则返回true
bool isOperator(char op);                         // 判断是否为运算符  
int getPriority(char op);                            // 求运算符优先级  
string infixToPostfix(string pre);    // 把中缀表达式转换为后缀表达式  
double readNumber(string str);            // 将数字字符串转变成相应的数字  
double getPostfixValue(string post);                // 由后缀表达式字符串计算相应的中值表达式的值    

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
		if (isNumber(pre[i])) {// 遇到数字直接写入后缀表达式  
			post.push_back(pre[i]);
		}
		else if (pre[i] == '(' || pre[i] == '（')   // 遇到“（”不用比较直接入栈  
			stack.push(pre[i]);
		else if (pre[i] == ')' || pre[i] == '）')  // 遇到右括号将其对应左括号后的操作符（操作符栈中的）全部写入后缀表达式  
		{
			while (stack.getTop() != '(' || stack.getTop() != '（')
			{
				post.push_back(stack.pop());
			}
			if (stack.isEmpty())
			{
				cout << "there is no '( ',eror equation";
				break;
			}
			else
				stack.pop(); // 将“（”出栈，后缀表达式中不含小括号  
		}
		else if (isOperator(pre[i]))
		{
			post.push_back(' ');; // 用空格分开操作数
			while (!stack.isEmpty() && getPriority(pre[i]) <= getPriority(stack.getTop()))
			{
				// 当前的操作符小于等于栈顶操作符的优先级时，将栈顶操作符写入到后缀表达式，重复此过程  
				post.push_back(stack.pop());
			}
			stack.push(pre[i]); // 当前操作符优先级大于栈顶操作符的优先级，将该操作符入栈  
		}
		i++;
	}
	while (!stack.isEmpty()) // 将所有的操作符加入后缀表达式  
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