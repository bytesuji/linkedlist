#ifndef LINKED_LIST_TCC
#define LINKED_LIST_TCC

#include <iostream>
#include <cassert>

template <typename T> struct node
{
	T data = 0;
	node *next = nullptr;
};

template <typename T> class LinkedList
{
private:
	node<T> *mHead;

public:
	LinkedList(node<T> *head = nullptr)
	{
		mHead = head;
	}

	~LinkedList()
	{
		node<T>* current = mHead;
		while(current != nullptr)
		{
			node<T> *next = current->next;
			delete current;
			current = next;
		}
	}

	// stack manip functions
	void push(node<T> *n)
	{
		n->next = mHead;
		mHead = n;
	}

 	node<T>* pop()
	{
		node<T> *copy = new node<T>();
		copy->data = mHead->data;
		copy->next = nullptr;

		node<T> *newHead = mHead->next;
		mHead->next = nullptr;
		mHead->data = 0;
		delete mHead;

		mHead = newHead;

		return copy;
	}

	void append(node<T> *n)
	{
		node<T> *end = mHead;
		while(end->next != nullptr)
		end = end->next;
		end->next = n;
	}

	void insert(short index, node<T> *n) // fix this
	{
		assert(index >= 0 && index < this->length());

		if(index == 0)
			this->push(n);
		else
		{
			short currentIndex = 0;
			node<T> *current = mHead;
			node<T> *prev = current;
			while(currentIndex != index)
			{
				prev = current;
				current = current->next;
				++currentIndex;
			}

			prev->next = n;
			n->next = current;
		}
	}

	// info functions
	node<T>* getHead()
	{
		return mHead;
	}

	node<T>* begin()
	{
		return mHead;
	}

	node<T>* end()
	{
		node<T> *current = mHead;
		node<T> *prev = nullptr;

		while(current != nullptr)
		{
			prev = current;
			current = current->next;
		}

		return prev;
	}

	size_t size()
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

	size_t length()
	{
		return this->size();
	}

	// overloads
	node<T>* operator[](int index)
	{
		assert(index >= 0 && index < this->length());

		int currentIndex = 0;
		node<T> *current = mHead;

		while(currentIndex != index)
		{
			current = current->next;
			++currentIndex;
		}

		return current;
	}
};

#endif

/* TODO
	add end and begin functions
	full list print function
*/
