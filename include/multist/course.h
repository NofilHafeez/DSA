#ifndef COURSE_H
#define COURSE_H
#include <string>
#include "student.h"
#include "studentList.h"

class Student;
// have to make the CourseList
class Course {

public:
    std::string courseName; // data part of the node
    Course* nextCours; // pointer to the next node
    StudentLinkedList* studentList; // pointer to the previous node

    Course(const std::string& name) {
        courseName = name; // initialize data
        nextCours = nullptr; // set next to nullptr initially
        // studentList = nullptr;
    }
};


#endif  // COURSE_H