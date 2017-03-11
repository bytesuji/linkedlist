#include "linkedlist_template.tcc"
#include <iostream>

using namespace std;

int main()
{
	node<int> *a = new node<int>;
	a->data = 1;
	LinkedList<int> ll(a);

	node<int> *b = new node<int>;
	b->data = 2;
	ll.append(b);

	cout << ll.length() << endl;
	cout << ll[1] << endl;

	return 0;
}
