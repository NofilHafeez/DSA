#include "../include/heap/heap.h"
#include <iostream>
#include <vector>
using namespace std;

    Heap::Heap(initializer_list<int> list){
    arr.push_back(-1); // dummy for 1-based indexing
    for (int x : list) {
        insert(x);
        sorting();
    }
}

    void Heap::insert(int value)
    {
        arr.push_back(value);
        int i = arr.size() - 1;

        while (i > 1)
        {
            int parent = i / 2;
            if (arr[parent] < arr[i])

            {
                cout << i << parent << endl;
                cout << "Swapping " << arr[parent] << " and " << arr[i] << endl;
                swap(arr[parent], arr[i]);
                i = parent;
            }
            else
                break;
        }
    }

    void Heap::deleteRoot(int value) {
        if ( value == arr[1] ) {
            arr[1] = arr.back();
            arr.pop_back();

            int i = 1;
            while (i < arr.size()) {
                int left = 2 * i;
                int right = 2 * i + 1;
                if (arr[left] > arr[i]) {
                    swap(arr[left], arr[i]);
                    break;
                } 
            }
        }

    }

    void Heap::sorting() {
            int i = 1;
            while (i <= (arr.size() - 1)) {
                cout << arr.size() << endl;
                int left = 2 * i;
                int right = 2 * i + 1;
                int largest = i;
                if (arr[left] > arr[i] && left < arr.size()) {
                    largest = left;
                } else if (arr[right] > arr[i] && right < arr.size()) {
                    largest = right;
                }

                if (largest != i) {
                    swap(arr[i], arr[largest]);
                    i = largest;
                } else {
                    break;
                }
            }
    }

    void Heap::print()
    {
        for (int i = 1; i < arr.size(); i++)
            cout << arr[i] << " ";
        cout << endl;
    }

