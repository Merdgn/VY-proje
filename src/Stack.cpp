#include <iostream>
#include "Stack.hpp"
using namespace std;

Stack::Stack(int capacity) : capacity(capacity), top(-1) {
    arr = new int[capacity];
}

Stack::~Stack() {
    delete[] arr;
}

void Stack::push(int value) {
    if (top >= capacity - 1) {
        // Stack is full, you can implement error handling here
        return;
    }

    arr[++top] = value;
}

int Stack::pop() {
    if (top < 0) {
        // Stack is empty, you can implement error handling here
        return -1;
    }

    return arr[top--];
}

bool Stack::isEmpty() {
    return top < 0;
}
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