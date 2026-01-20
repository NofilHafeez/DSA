#include "node.cpp"
using namespace std;
#include <iostream>

class DoubleCircularLinkedList
{
private:
   DoubleCircularNode* head;
   DoubleCircularNode* tail;
   
public: 
    DoubleCircularLinkedList() {
        head =  nullptr;
        tail = nullptr;
    }

    void insertAtHead(int value) {
    DoubleCircularNode* newNode = new DoubleCircularNode(value);

    if (head == nullptr) {
        head = tail = newNode;
        head ->prev = head;
        tail->next = head;
    } else {
        newNode->next = head;
        newNode->prev = tail;

        head->prev = newNode;
        tail->next = newNode;

        head = newNode;`
    }
}



  void insertAtTail(int value) {
    DoubleCircularNode* newNode = new DoubleCircularNode(value);

    if (tail == nullptr) {
        head = tail = newNode;
        head ->prev = head;
        head->next = head;  

    } else {
        newNode->prev = tail;
        newNode->next = head;

        tail->next = newNode;
        head->prev = newNode;

        tail = newNode;
    }
}



    void printForward() {
        DoubleCircularNode* temp = head;
        do {
            if (temp->next == head) {
                cout << temp->data << " -> (head)" ;
            } else{
                cout << temp->data << " -> ";
            }
            temp = temp->next;
        } while (temp != head);
        cout<< endl;
    }

    void printBackward() {
    DoubleCircularNode* temp = tail;
        do {
            if (temp->prev == tail) {
                cout << temp->data << " <- (tail)" ;
            } else{
                cout << temp->data << " <- ";
            }
            temp = temp->prev;
        } while (temp != tail);
    }



    void remove(int value) {
        if (head == nullptr) return;

        DoubleCircularNode* temp = head;
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