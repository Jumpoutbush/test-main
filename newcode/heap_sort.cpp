#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 调整堆
void heapify(vector<int>& arr, int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right < n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest); // 此时largest为left or right
    }
}

// 建立好初始大顶堆智慧，将堆顶元素与最后一个元素对换
// 数组长度 - 1， 忽略已排好的最大值?
// 调整为大顶堆
void heapSort(vector<int>& arr){
    int n = arr.size();
    // 构建大顶堆
    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(arr, n, i);
    }
    for(int i = n - 1; i > 0; i--){
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    // 定义一个待排序的数组?
    std::vector<int> arr = {12, 11, 13, 5, 6, 7, 14, 20, 15, 4, 9};

    std::cout << "排序前的数组: ";
    printArray(arr);

    // 调用堆排序函数对数组进行排序
    heapSort(arr);

    std::cout << "排序后的数组: ";
    printArray(arr);

    getchar();
    return 0;
}