#include "../include/stack/stack.h"
using namespace std;
#include <iostream>


Stack::Stack() : topNode(nullptr){}

void Stack::push(int value) {
    StackNode* newNode = new StackNode(value);
    if (isEmpty()) {
        topNode = newNode;
    } else {
        newNode->next = topNode;
        topNode = newNode;
    }
   
}

void Stack::pop() {
    if (isEmpty()) {
        return; // Stack is empty, nothing to pop
    }
    StackNode* temp = topNode;
    topNode = topNode->next;
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
        current = current->next;
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
        current = current->next;
    }
    cout << "Not Found: " << value << endl;
}

StackNode* Stack::merge(StackNode* s1, StackNode* s2){
        if (s1 == nullptr) return s2;
        if (s2 == nullptr) return s1;

        StackNode* temp = s1;
        while (temp->next != nullptr) {
            temp = temp->next;
         }
        temp->next = s2;
        return s1;
}

// 1 2 3 4 , // 5 6 7 8
// 3 s1   6 s2
// 2      5
// 1      4
