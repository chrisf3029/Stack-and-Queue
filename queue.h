//Christopher Fong
//File: queue.h

#pragma once

class Queue
{
public:
	Queue();
	Queue(const Queue& other);
	Queue& operator=(const Queue& other);
	~Queue();
	void clear();
	void enqueue(int val);
	void dequeue();
	void print() const;
	int peek();
	bool empty() const;
private:
	struct Node
	{
		int data;
		Node* next;
	};
	Node* head;
};