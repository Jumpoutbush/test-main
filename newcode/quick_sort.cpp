#include <iostream>
#include <algorithm>

void partition(int arr[], int start, int end)
{
    if(start >= end) return;
    int key = arr[start];
    int left = start, right = end;

    while(left < right){
        while(left < right && arr[right] >= key) right --;
        while(left < right && arr[left] <= key) left ++;
        std::swap(arr[left], arr[right]);
    }
    if(arr[left] < key){
        std::swap(arr[left], arr[start]);
    }
    partition(arr, start, left - 1);
    partition(arr, left + 1, end);
}
void quick_sort(int arr[], int len)
{
    partition(arr, 0, len - 1);
}

int main() {
    // 定义一个待排序的整数数组
    int arr[] = {5, 3, 8, 4, 2, 7, 1, 6};
    // 计算数组的长度
    int len = sizeof(arr) / sizeof(arr[0]);

    // 调用快速排序函数对数组进行排序
    quick_sort(arr, len);

    // 输出排序后的数组元素
    for (int i = 0; i < len; ++i) {
        std::cout << arr[i] << " ";
    }
    getchar();

    return 0;
}