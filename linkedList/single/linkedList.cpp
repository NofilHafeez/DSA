#include "node.cpp"
using namespace std;
#include <iostream>

class linkedList
{
private:
   Node* head;
   Node* tail;

public:
    linkedList() {
        head =  nullptr;
        tail = nullptr;
    }

    void insert(int value) {
    // "new" allocates memory on heap "Node" calls constructor of Node class
    // and returns the address of the newly created object
    // newNode  ---->  [ data | next ]
    //              value   NULL
    // Node* cur = head;
    Node* sort = head;
    Node* prev = nullptr;
    bool flag = false;

    // while (cur != nullptr) {
    //     if (cur->data == value) {
    //         cout << "Duplicate value " << value << " not inserted.\n";
    //         return;
    //     }
    //     cur = cur->next;
    // }

    Node* newNode = new Node(value); 

    if (head == nullptr) {
        head = tail = newNode;
        return;
    }

      while (sort != nullptr) {    
        if (sort->data > value) {  
            if (sort == head) {
                flag = true;    
                head = newNode;
                newNode->next = sort;
                return;
            } 
            flag = true;
            // middle insertion
            prev->next = newNode;
            newNode->next = sort;
            return;
        }
        prev = sort; 
        sort = sort->next;

        if (!flag && sort == nullptr) {
            tail->next = newNode;
            tail = newNode;
            return;
        }
    }

 }


    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }


    void remove(int value) {
        if (head == nullptr) return;

        Node* current = head;
        bool found = false; 

        while (current != nullptr ) { // stops when the node is detected
            if (current->data == value && current == head) {
                    found = true;
                    Node* toDelete = head; // node to be deleted
                    head = head->next; // move head to next node
                    current = head; // update current to new head
                    delete toDelete; // free memory 
                    continue;   
            } else if (current->next != nullptr && current->next->data == value) {
                    found = true;
                    Node* toDelete = current->next;
                    current->next = current->next->next; // bypass the node
                    delete toDelete;
                    // break;
                    continue;
            } 
            current = current->next; //prev node
            };

            if (!found) {
                cout << "Value " << value << " not found in the list.\n";
            }
    }
        
    void searching(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                cout << "Value " << value << " found in the list.\n";
                return;
            }
            current = current->next;
        }
        cout << "Value " << value << " not found in the list.\n";
    }

};

