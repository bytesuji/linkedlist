#include "linkedlist_template.tcc"
#include <iostream>

using namespace std;

int main()
{
	// create list
	node<int> *a = new node<int>;
	a->data = 1;
	LinkedList<int> ll(a);
	// add nodes
	node<int> *b = new node<int>;
	b->data = 2;
	ll.append(b);
	node<int> *c = new node<int>;
	c->data = 3;
	ll.append(c);
	node<int> *d = new node<int>;
	d->data = 4;
	ll.append(d);

	node<int> *aCopy = new node<int>;
	aCopy = ll.pop();
	cout << aCopy->data << endl;
	for(int i = 0; i < ll.length(); ++i)
		cout << ll[i]->data << " ";
	cout << endl;

	return 0;
}
