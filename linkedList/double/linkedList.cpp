#include "node.cpp"
using namespace std;
#include <iostream>

class DoubleLinkedList
{
private:
   DoubleNode* head;
   DoubleNode* tail;
public:
    DoubleLinkedList() {
        head =  nullptr;
        tail = nullptr;
    }

    void insertAtHead(int value) {
    DoubleNode* newNode = new DoubleNode(value);

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}



  void insertAtTail(int value) {
    DoubleNode* newNode = new DoubleNode(value);

    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}



    void printForward() {
        DoubleNode* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void printBackward() {
    DoubleNode* temp = tail;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->prev != nullptr)
            cout << " <- ";
        temp = temp->prev;
    }
    cout << endl;
}

    void remove(int value) {
        if (head == nullptr) return;

        DoubleNode* temp = head;
        while (temp->next != nullptr && temp->data != value) {
            temp = temp->next;
        }

        if (temp == head){
            head = temp->next;
            // if (head != nullptr) head->prev = nullptr;
        } else {
            temp->prev->next = temp->next;
        }   

        if (temp == tail) {
            tail = temp->prev;
            // if (tail != nullptr) tail->next = nullptr;
        } else {
            temp->next->prev = temp->prev;
        }

        delete temp;
    }
    
        


};

