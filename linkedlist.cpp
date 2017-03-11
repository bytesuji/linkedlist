#include "linkedlist.h"

LinkedList::LinkedList(node *head)
{
	mHead = new node;
	mHead = head;
}

LinkedList::~LinkedList()
{
	node* current = mHead;
	while(current != nullptr)
	{
		node *next = current->next;
		delete current;
		current = next;
	}
}

void LinkedList::push(node *n)
{
	n->next = mHead;
	mHead = n;
}

node* LinkedList::pop()
{
	node ret = *mHead;
	node *del = mHead;
	mHead = mHead->next;

	del->next = nullptr;
	del->data = 0;
	delete del;

	return &ret;
}

void LinkedList::append(node *n)
{
	node *end = mHead;
	while(end->next != nullptr)
		end = end->next;
	end->next = n;
}

node* LinkedList::getHead()
{
	return mHead;
}

short LinkedList::length()
{
	node *current = mHead;
	short cnt = 0;

	while(current != nullptr)
	{
		current = current->next;
		++cnt;
	}

	return cnt;
}

node* LinkedList::operator[](int index)
{
	int currentIndex = 0;
	node *current = mHead;

	while(currentIndex != index)
	{
		current = current->next;
		++currentIndex;
	}

	return current;
}
