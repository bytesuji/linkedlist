#ifndef LINKED_LIST_TCC
#define LINKED_LIST_TCC

#include <iostream>
#include <cassert>
#include <memory>

template <typename T>
struct node
{
	T data = 0;
	node *next = nullptr;
};

template <typename T>
class LinkedList
{
private:
	node<T> *mHead;
	short mSize;

public:
	LinkedList(node<T> *head = nullptr)
	{
		mHead = head;
		mSize = 0;
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

	// overloads
	node<T>* operator[](int index)
	{
		assert(index >= 0 && index < this->size());

		int currentIndex = 0;
		node<T> *current = mHead;

		while(currentIndex != index)
		{
			current = current->next;
			++currentIndex;
		}

		return current;
	}

	// stack manip functions
	void push(node<T> *n)
	{
		n->next = mHead;
		mHead = n;
		++mSize;
	}

 	std::unique_ptr<node<T>> pop() // uses unique_ptr to prevent a mem leak
	{
		std::unique_ptr<node<T>> copy(new node<T>);
		copy->data = mHead->data;
		copy->next = nullptr;

		node<T> *newHead = mHead->next; // doesn't need to be deleted because no alloc occurs
		mHead->next = nullptr;
		mHead->data = 0;
		delete mHead;

		mHead = newHead;
		--mSize;

		return copy;
	}

	void append(node<T> *n)
	{
		node<T> *end = mHead;
		while(end->next != nullptr)
		end = end->next;
		end->next = n;
		++mSize;
	}

	void remove(short index)
	{
		assert(index >= 0);

		if(index == 0)
			this->pop();
		else
		{
			if(index > this->size())
			{
				std::cerr << "(!) Warning: index > this->size(), removing last node.\n";
				index = this->size() - 1;
			}

			short currentIndex = 0;
			node<T> *current = mHead;
			node<T> *prev = current;
			while(currentIndex != index)
			{
				prev = current;
				current = current->next;
				++currentIndex;
			}

			prev->next = current->next;
			current->next = nullptr;
			delete current;
		}
		--mSize;
	}

	void insert(short index, node<T> *n)
	{
		assert(index >= 0);

		if(index == 0)
			this->push(n);
		else if(index > 0 && index < this->size())
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
		else
		{
			std::cerr << "(!) Warning: index greater than this->size(), appending node.\n";
			this->append(n);
		}
		++mSize;
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
		return this[0][mSize - 1];
	}

	size_t size()
	{
		return mSize;
	}

	size_t length()
	{
		return this->size();
	}

};

#endif

/* TODO
	full list print function
	getIndex function
*/
