#include<iostream>
#include "list.cpp"
#include "node.cpp"
using namespace std;

int main(){
	List* l = new List();
	List* l2 = new List();

    for (int i = 0; i < 10; ++i) {
        l->insertHead(i);
        l2->insertHead(i);
    }

    if(l == l2) {
        cout << "equal" << endl;
    }

    //l->print();

    //l->printReverse();

    //l->remove(0);

    //l->print();

    //l->insertIntoPos(6,77);

    /*
    l->insertEnd(99);
    l->insert(88);
    l->print();

    if(l->search(99)) {
        cout << "found" << endl;
    } else {
        cout << "Not found" << endl;
    }
    */

    delete l;

    return 0;
}
