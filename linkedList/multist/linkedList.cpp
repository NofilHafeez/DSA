#include "student.h"
#include "course.h"
using namespace std;
#include <iostream>

class StudentLinkedList
{
private:
   Student* head;
   Student* tail;
   
public: 
    StudentLinkedList() {
        head =  nullptr;
        tail = nullptr;
    }

    void insert(string name, int code) {
    Course* coursePtr = new Course(code); // or assign to an existing Course node if needed
    Student* newStudent = new Student(name, coursePtr);

    if (head == nullptr) {
        head = tail = newStudent;
    } else {
       tail->nextStudent = newStudent;
       tail = newStudent;
    }
}

    void print() {
    Student* temp = head;
    while (temp != nullptr) {
        cout << temp->name << " -> ";
        temp = temp->nextStudent;
    }
    cout << "NULL\n";
}

    // void remove(int value) {
    //     if (head == nullptr) return;

    //     DoubleCircularNode* temp = head;

    //     if (head == tail && head->data == value) {
    //         delete head;
    //         head = tail = nullptr;
    //         return;
    //     }

    //     while (temp->data != value) 
    //     {
    //         temp = temp->next;
    //         if (temp == head) return; // Value not found
    //     }

    //     if (temp->data == value) {
    //         temp->prev->next = temp->next;
    //         temp->next->prev = temp->prev;

    //         // if value is head or tail, update head and tail pointers
    //         if (temp == head) head = head->next;
    //         if (temp == tail) tail = tail->prev;

    //         delete temp;
    //     }
        
    // }
    
        


};