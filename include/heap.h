#pragma once
#include <vector>

class Heap {
    public:
    vector<int> arr;
    Heap(initializer_list<int> list);
    void insert(int);
    void deleteRoot(int);
    void sorting();
    void print();
};