#include <iostream>
#include <algorithm>
using namespace std;

int partition(int arr[], int start, int end)
{
    if(start >= end) return start;
    int randomIndex = start + rand() % (end - start + 1);
    std::swap(arr[start], arr[randomIndex]);
    int key = arr[start];
    int left = start, right = end;
    while(left < right){
        while(left < right && arr[right] >= key) right--;
        while(left < right && arr[left] <= key) left++;
        swap(arr[left], arr[right]);
    }
    if(arr[left] < key){
        swap(arr[left], arr[start]);
    }
    return left;
}
void quick_sort(int arr[], int start, int end)
{
    if(start < end){
        int pivotIndex = partition(arr, start, end);
        quick_sort(arr, start, pivotIndex - 1);
        quick_sort(arr, pivotIndex + 1, end);
    }
}

int main() {
    // 定义一个待排序的整数数组
    int arr[] = {5, 3, 8, 4, 2, 7, 1, 6};
    // 计算数组的长度
    int len = sizeof(arr) / sizeof(arr[0]);

    // 调用快速排序函数对数组进行排序
    quick_sort(arr, 0, len - 1);

    // 输出排序后的数组元素
    for (int i = 0; i < len; ++i) {
        std::cout << arr[i] << " ";
    }
    getchar();

    return 0;
}