#ifndef STACK_HPP
#define STACK_HPP

class Stack {
private:
    int* arr;
    int capacity;
    int top;

public:
    Stack(int capacity);
    ~Stack();

    void push(int value);
    int pop();
    bool isEmpty();
};

#endif
