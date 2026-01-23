#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using std::string;

class Course; 

// Pass big objects (string, vector, class objects) by "const &"

class Student {
public:
    string name; // data part of the node
    Student* nextStudent; // pointer to the next node
    Course* courseLink; // pointer to the course node

    // const string& → pass by reference
    // No copy is made
    // Just points to the original strin
    // const → ensures the constructor cannot modify the original string
    Student(const string& studentName, Course* coursePtr = nullptr) {
        name = studentName; // initialize data
        nextStudent = nullptr; // set next to nullptr initially
        courseLink = coursePtr; // set courseLink to the provided course pointer
    }
};

#endif  // STUDENT_H

