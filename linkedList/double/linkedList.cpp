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
    
     void searching(int value) {
        DoubleNode* current = head;
        while (current != nullptr) {
            if (current->data == value) {
                cout << "Value " << value << " found in the list.\n";
                return;
            }
            current = current->next;
        }
        cout << "Value " << value << " not found in the list.\n";
    }

    Node* merge(Node* head1, Node* head2)
{
    if (head1 == nullptr)
        return head2;

    if (head2 == nullptr)
        return head1;

    Node* head = nullptr;
    Node* tail = nullptr;

    while (head1 != nullptr && head2 != nullptr)
    {
        Node* temp;

        if (head1->data <= head2->data)
        {
            temp = head1;
            head1 = head1->next;
        }
        else
        {
            temp = head2;
            head2 = head2->next;
        }

        temp->next = nullptr;

        if (head == nullptr)
        {
            head = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }

    if (head1 != nullptr)
        tail->next = head1;

    if (head2 != nullptr)
        tail->next = head2;

    return head;
}


    Node* findMiddle(Node* head)
{
    if (head == nullptr)
        return nullptr;

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

    void palindrome()
{
    Node* mid = findMiddle(head);

    string first = "";
    string second = "";

    Node* temp = head;

    while (temp != mid)
    {
        first += to_string(temp->data) + ",";
        temp = temp->next;
    }

    while (mid != nullptr)
    {
        second += to_string(mid->data) + ",";
        mid = mid->next;
    }

    reverse(second.begin(), second.end());

    if (first == second)
        cout << "Palindrome";
    else
        cout << "Not Palindrome";
}

};

