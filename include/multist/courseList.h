#pragma once
#include "course.h"
#include <string>

class CourseLinkedList {

public:
    Course* head;
    Course* tail;
    CourseLinkedList();
    void insert(const std::string& courseName);
    Course* find(const std::string& courseName);
    void remove(const std::string& courseName);
    void print();
};
