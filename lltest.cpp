#include "linkedlist.tcc"
#include <iostream>

using namespace std;

int main()
{
	cout << "/// BEGIN TESTS ///\n\n";
	node<int> *a = new node<int>;
	node<int> *b = new node<int>;
	node<int> *c = new node<int>;

	a->data = 1;
	b->data = 2;
	c->data = 3;

	LinkedList<int> ll(a);
	ll.append(b);
	ll.append(c);

	node<int> *d = new node<int>;
	d->data = 0;
	ll.push(d);

	for(int i = 0; i < ll.size(); ++i)
		cout << ll[i]->data << " ";
	cout << endl;

	cout << ll.pop()->data << endl; // leaks memory

	node<int> *e = new node<int>;
	e->data = 4;
	ll.append(e);

	for(int i = 0; i < ll.size(); ++i)
		cout << ll[i]->data << " ";
	cout << endl;

	node<int> *camsData = new node<int>;
	camsData->data = 17;
	ll.insert(100, camsData);

	for(int i = 0; i < ll.size(); ++i)
		cout << ll[i]->data << " ";
	cout << endl;

	cout << "POP\n";
	cout << ll.pop()->data << endl;

	cout << "begin = " << ll.begin()->data << endl;
	cout << "end = " << ll.end()->data << endl;
	cout << ll.size() << endl;

	for(int i = 0; i < ll.size(); ++i)
		cout << ll[i]->data << " ";
	cout << endl;

	ll.remove(10);

	for(int i = 0; i < ll.size(); ++i)
		cout << ll[i]->data << " ";
	cout << endl;
	ll.print();

	node<int> *t = new node<int>;
	t->data = 9;
	ll.append(t);

	node<int> *there_are_too_many_of_these = new node<int>;
	there_are_too_many_of_these->data = 51;
	ll.append(there_are_too_many_of_these);

	ll.print();
	
	cout << "the node containing 9 is at index " << ll.linearSearch(9) << endl;


	cout << "\n/// END TESTS ///\n";

	return 0;
}
