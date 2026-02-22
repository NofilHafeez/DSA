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
        if (left > right)
            return;

        int pivot = partition(arr, left, right);
        // int pivot = setPivot(arr, left, right);

        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);   

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

         int setPivot(vector<int>& arr, int left, int right) {
            int pivot = (left + right) / 2;
             
            while (left  < right) {
                
                while (pivot != right) {
                    if (arr[pivot] > arr[right]) {
                        swap(arr[pivot], arr[right]);
                        pivot = right;
                        // break;
                    } else {
                        right--;
                    }
                }

                while (pivot != left) {
                    if (arr[pivot] < arr[left]) {
                        swap(arr[pivot], arr[left]);
                        pivot = left;

                        // break;
                    } else {
                        left++;
                    }
                }
            }
            return pivot;
        }
};

     