#include "../../include/multiList/student.h"
#include "../../include/multiList/studentList.h"

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



    void StudentLinkedList::remove(const std::string& name) {
        if (!head) return;

        while (head && head->name == name) {
            Student* del = head;
            head = head->nextStudent;
            delete del;
        }

        Student* current = head;
        while (current && current->nextStudent) {
            if (current->nextStudent->name == name) {
                Student* del = current->nextStudent;
                current->nextStudent = del->nextStudent;
                delete del;
            } else {
                current = current->nextStudent;
            }
        }
    }

