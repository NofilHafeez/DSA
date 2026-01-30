#include <iostream>
using namespace std;
// #include "models/searchingAlgo.cpp"
// #include "models/sortingAlgo.cpp"
// #include "include/single/linkedList.h"
// #include "linkedList/double/linkedList.cpp"
// #include "linkedList/circular/linkedList.cpp"
// #include "linkedList/multist/linkedList.cpp"
// #include "heap/heap.cpp"
#include "linkedList/multist/studentList.cpp"
#include "linkedList/multist/courseList.cpp"


int main(int argc, char** argv) {

    CourseLinkedList courseList;
  
    courseList.insert("maths");
    Course* math = courseList.find("maths");
    
    math->studentList = new StudentLinkedList();
    math->studentList->insert("Alice");
    math->studentList->insert("bob");

    Student* alice = math->studentList->find("Alice");
    cout << "Found student: " << alice->name << endl;

    math->studentList->print(); 
    courseList.print();





    return 0;
}