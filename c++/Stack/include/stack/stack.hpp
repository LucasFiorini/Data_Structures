#ifndef STACK_H
#define STACK_H 1

class Stack {
public:
    Stack();
    Stack(const Stack& s);
    ~Stack();
    void copyToArray(int arr[]);
    unsigned int peek();
    unsigned int pop();
    void push(int data);
private:
    Node* head, tail;
    unsigned int size;
};

#define