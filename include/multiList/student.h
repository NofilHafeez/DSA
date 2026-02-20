#ifndef STUDENT_H
#define STUDENT_H
#include <string>
using std::string;



// Pass big objects (string, vector, class objects) by "const &"

class Student {
public:
    string name; // data part of the node
    Student* nextStudent; // pointer to the next node

    // const string& → pass by reference
    // No copy is made
    // Just points to the original strin
    // const → ensures the constructor cannot modify the original string
    Student(const string& studentName) {
    name = studentName;
    nextStudent = nullptr;
    }

};

#endif  // STUDENT_H

