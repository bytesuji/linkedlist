#include "linkedlist.h"
#include <iostream>

using namespace std;

int main()
{
	node *a = new node;
	a->data = 1;
	LinkedList ll(a);

	node *b = new node;
	b->data = 2;
	ll.append(b);

	cout << ll.length() << endl;
	cout << ll[1] << endl;

	return 0;
}
