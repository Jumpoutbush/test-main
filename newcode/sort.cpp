#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// 插入排序
void insertionSort(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// 堆排序
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int>& arr, int left, int right) {
    int n = right - left + 1;
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; --i) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// 快速排序分区函数
int partition(std::vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j < right; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[right]);
    return i + 1;
}

// 内省排序
void introSort(std::vector<int>& arr, int left, int right, int depthLimit) {
    if (right - left < 16) {
        insertionSort(arr, left, right);
    } else if (depthLimit == 0) {
        heapSort(arr, left, right);
    } else {
        int pivotIndex = partition(arr, left, right);
        introSort(arr, left, pivotIndex - 1, depthLimit - 1);
        introSort(arr, pivotIndex + 1, right, depthLimit - 1);
    }
}

// 封装内省排序
void introsort(std::vector<int>& arr) {
    int n = arr.size();
    int depthLimit = 2 * std::log2(n);
    introSort(arr, 0, n - 1, depthLimit);
}

int main() {
    std::vector<int> arr = {5, 2, 9, 1, 5, 6};
    introsort(arr);
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}