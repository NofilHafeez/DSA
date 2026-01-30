#include "../../include/multist/student.h"
#include "../../include/multist/studentList.h"

#include <iostream>


    StudentLinkedList::StudentLinkedList() {
        head = tail = nullptr;
    }

    Student* StudentLinkedList::insert(const std::string& name) {
        Student* newStudent = new Student(name);

        if (!head) {
            head = tail = newStudent;
        } else {
            tail->nextStudent = newStudent;
            tail = newStudent;
        }
        return newStudent;
    }

   void StudentLinkedList::print() {
    Student* temp = head;

    while (temp != nullptr) {
        std::cout << temp->name << " -> ";
        temp = temp->nextStudent;
    }
    std::cout << "NULL\n";
}


    Student* StudentLinkedList::find(const std::string& name) {
        Student* temp = head;

        while (temp != nullptr) {
            if (temp->name == name) {
                return temp;
            }
            temp = temp->nextStudent;
        }
        return nullptr;
    }
