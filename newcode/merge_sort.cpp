#include <iostream>
#include <vector>

// 合并两个已排序的子数组
void merge(std::vector<int>& nums, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 创建临时数组
    std::vector<int> L(n1), R(n2);

    // 复制数据到临时数组 L[] 和 R[]
    for (int i = 0; i < n1; i++)
        L[i] = nums[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = nums[mid + 1 + j];

    // 归并临时数组到 nums[left..right]
    int i = 0; // 初始化第一个子数组的索引
    int j = 0; // 初始化第二个子数组的索引
    int k = left; // 初始归并子数组的索引

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            nums[k] = L[i];
            i++;
        } else {
            nums[k] = R[j];
            j++;
        }
        k++;
    }

    // 复制 L[] 的剩余元素
    while (i < n1) {
        nums[k] = L[i];
        i++;
        k++;
    }

    // 复制 R[] 的剩余元素
    while (j < n2) {
        nums[k] = R[j];
        j++;
        k++;
    }
}

// 归并排序函数
void mergeSort(std::vector<int>& nums, int left, int right) {
    if (left < right) {
        // 找到中间点
        int mid = left + (right - left) / 2;

        // 递归排序左半部分
        mergeSort(nums, left, mid);
        // 递归排序右半部分
        mergeSort(nums, mid + 1, right);

        // 合并已排序的两部分
        merge(nums, left, mid, right);
    }
}

// 封装的归并排序函数
std::vector<int> sortArray(std::vector<int>& nums) {
    int n = nums.size();
    mergeSort(nums, 0, n - 1);
    return nums;
}


int main()
{
    std::vector<int> nums = {5, 2, 3, 1, 4, 6, 9, 8, 7};
    std::vector<int> sorted = sortArray(nums);
    for(int i = 0; i < sorted.size(); ++i){
        std::cout << sorted[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}