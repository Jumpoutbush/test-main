#include <iostream>
#include <vector>

class BubbleSorter {
public:
    // 冒泡排序函数，使用 std::vector 按值传递
    std::vector<int> bubbleSort(std::vector<int>& vec) {
        int size = vec.size();
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (vec[j] > vec[j + 1]) {
                    // 交换 vec[j] 和 vec[j+1]
                    int temp = vec[j];
                    vec[j] = vec[j + 1];
                    vec[j + 1] = temp;
                }
            }
        }
        return vec;
    }

    // 打印向量函数
    void printVector(const std::vector<int>& vec) {
        for (int num : vec) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    BubbleSorter sorter;
    std::vector<int> vec = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "Original vector: ";
    sorter.printVector(vec);

    // 调用冒泡排序函数，按值传递
    std::vector<int> sortedVec = sorter.bubbleSort(vec);

    std::cout << "Original vector after sort call: ";
    sorter.printVector(vec);

    std::cout << "Sorted vector: ";
    sorter.printVector(sortedVec);
    system("pause");
    return 0;
}