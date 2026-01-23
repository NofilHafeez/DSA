#ifndef COURSE_H
#define COURSE_H

class Student;
// have to make the CourseList
class Course {
public:
    int code; // data part of the node
    Course* nextCours; // pointer to the next node
    Student* studentLink; // pointer to the previous node

    Course(int code) {
        code = code; // initialize data
        nextCours = nullptr; // set next to nullptr initially
        studentLink = nullptr; // set prev to nullptr initially
    }
};


#endif  // COURSE_H