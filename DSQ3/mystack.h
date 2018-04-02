#pragma once
#ifndef MYSTACK
#define MYSTACK
#include <iostream>
using namespace std;
template<typename T>
struct Node
{
	T data;
	Node<T>*next;
	Node(Node<T>*next = nullptr) { this->next = next; }
	Node(const T &data, Node<T> *next = nullptr) {
		this->data = data;
		this->next = next;
	}
};
template<typename T>
class MyStack {
private:
	Node<T> *top;
public:
	MyStack() { top = nullptr; }
	~MyStack() {
		Node<T>*tmp;
		while (top != nullptr) {
			tmp = top;
			top = top->next;
			delete tmp;
		}
		delete top;
	}
	void clear() {
		Node<T>*tmp;
		while (top != nullptr) {
			tmp = head;
			head = head->next;
			delete tmp;
		}
	}
	void push(const T data) {
		Node<T> *s;
		s = new Node<T>;
		s->data = data;
		s->next = top;
		top = s;
	}
	T pop() {
		Node<T> *p;
		T result = 0;
		if (top != nullptr) {
			result = top->data;
			p = top;
			top = top->next;
			delete p;
		}
		else cout << "stack is empty.please push data first!"<< endl;
		return result;
	}
	T getTop() {
		if (top != nullptr)
			return top->data;
		else
		{
			cout << "stack is empty!";
			exit(1);
		}
	}
	bool isEmpty() {
		if (top == nullptr)
			return true;
		else
			return false;
	}
};

#endif//MYSTACK