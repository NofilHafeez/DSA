#include <iostream>
#include <vector>
using namespace std;

class QuickSort {
    vector<int> temp;

public:
    void sort(vector<int>& arr) {
        temp.resize(arr.size());
        quickSort(arr, 0, arr.size() - 1);
    }

private:
    void quickSort(vector<int>& arr, int left, int right) {
        if (left >= right)
            return;

        int j = partition(arr, left, right);
        quickSort(arr, left, j - 1);
        quickSort(arr, j + 1, right);

    }

        int partition(vector<int>& arr, int left, int right) {
            int pivot = arr[left];
            int i = left;
            int j = right + 1;  
            

            while (i < j) {
                do
                {
                i++;  
                } while ( i <= right && arr[i] < pivot);

                do
                {
                j--;
                } while (arr[j] > pivot);

                if (i < j) {
                    swap(arr[i], arr[j]);
                }
            }

            swap(arr[left], arr[j]);
            return j;
        }
};