//Christopher Fong
//File: queue.cpp

#include <iostream>
#include "queue.h"

using namespace std;

Queue::Queue()
{
	head = nullptr;
}
Queue::Queue(const Queue& other)
{
	head = nullptr;
	Node* temp = head;
	Node* temp2 = other.head;
	while (temp != nullptr)
	{
		temp = new Node;
		temp->data = temp2->data;
		temp = temp->next;
		temp2 = temp2->next;
	}
}
Queue& Queue::operator=(const Queue& other)
{
	clear();
	head = nullptr;
	Node* temp = head;
	Node* temp2 = other.head;
	while (temp != nullptr)
	{
		temp = new Node;
		temp->data = temp2->data;
		temp = temp->next;
		temp2 = temp2->next;
	}
	return *this;
}
Queue::~Queue()
{
	clear();
}
void Queue::clear()
{
	while (head != nullptr)
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	delete head;
}
void Queue::enqueue(int val)
{
	Node* value = new Node;
	value->data = val;
	value->next = nullptr;
	if (head == nullptr)
	{
		head = value;
	}
	else
	{
		Node* temp = head;
		while (temp->next != nullptr)
			temp = temp->next;
		temp->next = value;
	}
}
void Queue::dequeue()
{
	Node* temp = head;
	head = head->next;
	delete temp;
}
void Queue::print() const
{
	Node* temp = head;
	while (temp != nullptr)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
int Queue::peek()
{
	return head->data;
}
bool Queue::empty() const
{
	return head == nullptr;
}