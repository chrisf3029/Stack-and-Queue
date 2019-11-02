//Christopher Fong
//File: stack.cpp

#include "stack.h"

using namespace std;

Stack::Stack()
{
	arr = new int[size];
}
Stack::Stack(const Stack& other)
{
	size = other.size;
	pushes = other.pushes;
	arr = new int[size];
	for (int i = 0; i < size; i++)
		arr[i] = other.arr[i];
}
Stack& Stack::operator=(const Stack& other)
{
	size = other.size;
	pushes = other.pushes;
	arr = new int[size];
	for (int i = 0; i < size; i++)
		arr[i] = other.arr[i];
	return *this;
}
Stack::~Stack()
{
	for (int i = 0; i < pushes; i++)
		pop();
	delete [] arr;
}
void Stack::push(int val)
{
	if (pushes >= size)
	{
		int* temp = new int[size];
		for (int i = 0; i < size; i++)
			temp[i] = arr[i];
		delete[] arr;
		size *= 2;
		arr = new int[size];
		for (int i = 0; i < size; i++)
			arr[i] = temp[i];
		delete[] temp;
	}
	for (int i = pushes; i > 0; i--)
		arr[i] = arr[i - 1];
	pushes++;
	arr[0] = val;

}
void Stack::pop()
{
	for (int i = 0; i < pushes; i++)
		arr[i] = arr[i + 1];
	pushes--;
}
int Stack::peek()
{
	return arr[0];
}
bool Stack::empty() const
{
	return pushes == 0;
}
