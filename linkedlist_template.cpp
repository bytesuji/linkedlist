//DO NOT USE
/*
#include "linkedlist_template.h"

template <typename T>
LinkedList<T>::LinkedList(node<T> *head)
{
	mHead = new node<T>;
	mHead = head;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	node<T>* current = mHead;
	while(current != nullptr)
	{
		node<T> *next = current->next;
		delete current;
		current = next;
	}
}

template <typename T>
void LinkedList<T>::push(node<T> *n)
{
	n->next = mHead;
	mHead = n;
}

template <typename T>
node<T>* LinkedList<T>::pop()
{
	node<T> ret = *mHead;
	node<T> *del = mHead;
	mHead = mHead->next;

	del->next = nullptr;
	del->data = 0;
	delete del;

	return &ret;
}

template <typename T>
void LinkedList<T>::append(node<T> *n)
{
	node<T> *end = mHead;
	while(end->next != nullptr)
		end = end->next;
	end->next = n;
}

template <typename T>
node<T>* LinkedList<T>::getHead()
{
	return mHead;
}

template <typename T>
short LinkedList<T>::length()
{
	node<T> *current = mHead;
	short cnt = 0;

	while(current != nullptr)
	{
		current = current->next;
		++cnt;
	}

	return cnt;
}

template <typename T>
node<T>* LinkedList<T>::operator[](int index)
{
	int currentIndex = 0;
	node<T> *current = mHead;

	while(currentIndex != index)
	{
		current = current->next;
		++currentIndex;
	}

	return current;
}

*/
