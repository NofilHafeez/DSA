#include "../../include/single/linkedList.h"
#include <iostream>
using namespace std;

linkedList::linkedList() {
    head = nullptr;
    tail = nullptr;
}

void linkedList::insert(int value) {
    Node* sort = head;
    Node* prev = nullptr;

    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = tail = newNode;
        return;
    }

    while (sort != nullptr) {
        if (sort->data > value) {
            if (sort == head) {
                newNode->next = head;
                head = newNode;
                return;
            }
            prev->next = newNode;
            newNode->next = sort;
            return;
        }
        prev = sort;
        sort = sort->next;
    }

    tail->next = newNode;
    tail = newNode;
}

void linkedList::print() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void linkedList::printRecursionForward(Node* temp) {
    if (temp == nullptr) {
        cout << "NULL";
        return;
    }
    cout << temp->data << " -> ";
    // temp = temp -> next;
    printRecursionForward(temp -> next);
} 

void linkedList::printRecursionBackward(Node* temp) {
    if (temp == nullptr) {
        cout << "NULL <-";
        return;
    }
    printRecursionBackward(temp -> next);
    cout << temp->data << " <- ";
}


// ✔ Deletes all occurrences
// ✔ Handles head deletion correctly
// ✔ Safe traversal
void linkedList::remove(int value) {
    if (!head) return;

    while (head && head->data == value) {
        Node* del = head;
        head = head->next;
        delete del;
    }

    Node* current = head;
    while (current && current->next) {
        if (current->next->data == value) {
            Node* del = current->next;
            current->next = del->next;
            delete del;
        } else {
            current  = current->next;
        }
    }
}


// Best for removing a known node pointer
void linkedList::removeBetter(Node* entry) {
    if (!head) return;

    Node** indirect = &head;

    while((*indirect) != entry && *indirect) {
        indirect = &(*indirect)->next;
    }

    if (*indirect) {
        *indirect = entry->next;
        delete entry;
    }
}

//  Node* linkedListt::swapPairs(ListNode* head) {
//         if (head == nullptr) return nullptr;

//         if (head->next == nullptr) {
//             return head;
//         }
//         ListNode* newHead = head->next;
//         ListNode* a = nullptr;
//         ListNode* b = nullptr;
//         ListNode* curr = head;
//         ListNode* prev = nullptr;
        
        
//         while (curr != nullptr && curr->next != nullptr) {
//             a = curr;
//             b = curr->next;
//             // prev = curr;
//             if (a != nullptr && b != nullptr) {
//                 a->next = b->next;
//                 b->next = a;
//                 // prev->next = b;
//             }

//             if (prev != nullptr)
//                 prev->next = b;

//             prev = curr;
//             curr = a -> next;
//         }
//         return newHead;
//     }

void linkedList::searching(int value) {
    Node* current = head;
    while (current) {
        if (current->data == value) {
            cout << "Value " << value << " found\n";
            return;
        }
        current = current->next;
    }
    cout << "Value " << value << " not found\n";
}
