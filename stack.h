//Christopher Fong
//File: stack.h

#pragma once

class Stack
{
public:
	Stack();
	Stack(const Stack& other);
	Stack& operator=(const Stack& other);
	~Stack();
	void push(int val);
	void pop();
	int peek();
	bool empty() const;
private:
	int pushes = 0;
	int size = 52;
	int* arr;
};
