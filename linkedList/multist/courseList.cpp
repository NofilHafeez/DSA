#include <string>
#include "../../include/multist/courseList.h"
#include "../../include/multist/course.h"

#include <iostream>

CourseLinkedList::CourseLinkedList() {
    head = nullptr;
    tail = nullptr;
}

void CourseLinkedList::insert(const std::string& courseName) {
     Course* coursePtr = new Course(courseName);

    if (head == nullptr) {
        head = tail = coursePtr;
    } else {
        tail->nextCours = coursePtr;
        tail = coursePtr;
    }
}

void CourseLinkedList::print() {
    Course* temp = head;

    while (temp != nullptr) {
        Student* s = temp->studentList->head;
        std::cout << temp->courseName << " -> ( ";
        while (s != nullptr) {
            std::cout << s->name << ", ";
            s = s->nextStudent;
        }
        std::cout << "NULL";
        cout << " )  -> ";
        temp = temp->nextCours;
    }
    std::cout << "NULL\n";
}

Course* CourseLinkedList::find(const std::string& courseName) {
    Course* temp = head;

    while (temp != nullptr) {
        if (temp->courseName == courseName) {
            return temp;
        }
        temp = temp->nextCours;
    }
    return nullptr;
}

