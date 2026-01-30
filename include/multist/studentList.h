#pragma once
#include "student.h"
#include <string>

class StudentLinkedList {

public:
    Student* head;
    Student* tail;
    StudentLinkedList();
    Student* insert(const std::string& name);
    Student* find(const std::string& name);
    void print();
};
