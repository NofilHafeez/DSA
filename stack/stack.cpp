#include "../include/stack/stack.h"
using namespace std;
#include <iostream>


Stack::Stack() : topNode(nullptr) {}

void Stack::push(int value) {
    StackNode* newNode = new StackNode(value);
    newNode->topNode = topNode;
    topNode = newNode;
}

void Stack::pop() {
    if (isEmpty()) {
        return; // Stack is empty, nothing to pop
    }
    StackNode* temp = topNode;
    topNode = topNode->topNode;
    delete temp;
}

int Stack::top() const {
    if (isEmpty()) {
        return -1; // Stack is empty
    }
    return topNode->data;
}

bool Stack::isEmpty() const {
    return topNode == nullptr;
}

void Stack::print() {
    StackNode* current = topNode;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->topNode;
    }
    cout << endl;
}

void Stack::searching(int value) {
    StackNode* current = topNode;
    while (current != nullptr) {
        if (current->data == value) {
            cout << "Found: " << value << endl;
            return;
        }
        current = current->topNode;
    }
    cout << "Not Found: " << value << endl;
}