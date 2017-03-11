#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct node
{
	int data;
	node *next = nullptr;
} node;

template <class T>
class C_NODE
{
public:
	T data;
	C_NODE *next = nullptr;
}

class LinkedList
{
private:
	node *mHead;

public:
	LinkedList(node *head = nullptr);
	~LinkedList();

	// stack manip functions
	void push(node *n);
	node* pop();
	void append(node *n);

	// info functions
	node* getHead();
	short length();

	// overloads
	node* operator[](int index);
};

#endif
