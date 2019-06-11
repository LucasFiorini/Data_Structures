#include "../../include/stack/stack.hpp"
#include "../../include/stack/node.hpp"

#include <iostream>
using namespace std;

int main() {

    Stack* s = new Stack();

    for (unsigned int i = 0; i < 10; ++i) {
        s->push(i);
    }

    s->pop();
    s->print();

    return 0;
}