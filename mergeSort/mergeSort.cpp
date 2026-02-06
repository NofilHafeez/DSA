#include <iostream>
#include <vector>
using namespace std;

class MergeSort {
    vector<int> temp;

public:
    void sort(vector<int>& arr) {
        temp.resize(arr.size());
        mergeSort(arr, 0, arr.size() - 1);
    }

private:
    void mergeSort(vector<int>& arr, int left, int right) {
        if (left >= right)
            return;

        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    void merge(vector<int>& arr, int left, int mid, int right) {
        for (int i = left; i <= right; i++)
            temp[i] = arr[i];

        int i = left;
        int j = mid + 1;
        int k = left;

        while (i <= mid && j <= right) {
            if (temp[i] <= temp[j])
                arr[k++] = temp[i++];
            else
                arr[k++] = temp[j++];
        }

        while (i <= mid)
            arr[k++] = temp[i++];

        while (j <= right)
            arr[k++] = temp[j++];
    }
};