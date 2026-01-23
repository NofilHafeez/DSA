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

        head = newNode;
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

        if (head == tail && head->data == value) {
            delete head;
            head = tail = nullptr;
            return;
        }

        while (temp->data != value) 
        {
            temp = temp->next;
            if (temp == head) return; // Value not found
        }

        if (temp->data == value) {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            // if value is head or tail, update head and tail pointers
            if (temp == head) head = head->next;
            if (temp == tail) tail = tail->prev;

            delete temp;
        }
        
    }


     void searching(int value) {
        DoubleCircularNode* current = head;
        do {
            if (current->data == value) {
                cout << "Value " << value << " found in the list.\n";
                return;
            }  
            current = current->next;
        } while (current != head);
        cout << "Value " << value << " not found in the list.\n";
    }
    
        


};