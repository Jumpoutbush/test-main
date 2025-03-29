#include <iostream>
#include <vector>

template<typename T>
class PriorityQueue {
private:
    std::vector<T> heap;

    // 上浮操作，用于维护堆的性质
    void swim(int k) {
        while (k > 0 && heap[(k - 1) / 2] < heap[k]) {
            std::swap(heap[(k - 1) / 2], heap[k]);
            k = (k - 1) / 2;
        }
    }

    // 下沉操作，用于维护堆的性质
    void sink(int k) {
        int n = heap.size();
        while (2 * k + 1 < n) {
            int j = 2 * k + 1;
            if (j + 1 < n && heap[j] < heap[j + 1]) {
                j++;
            }
            if (heap[k] >= heap[j]) {
                break;
            }
            std::swap(heap[k], heap[j]);
            k = j;
        }
    }

public:
    // 向优先级队列中插入元素
    void push(const T& value) {
        heap.push_back(value);
        swim(heap.size() - 1);
    }

    // 移除并返回优先级最高的元素
    T pop() {
        if (heap.empty()) {
            throw std::out_of_range("Priority queue is empty");
        }
        T max = heap[0];
        std::swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        sink(0);
        return max;
    }

    // 返回优先级最高的元素
    T top() const {
        if (heap.empty()) {
            throw std::out_of_range("Priority queue is empty");
        }
        return heap[0];
    }

    // 检查优先级队列是否为空
    bool empty() const {
        return heap.empty();
    }

    // 返回优先级队列中元素的数量
    size_t size() const {
        return heap.size();
    }
};

int main() {
    PriorityQueue<int> pq;

    // 插入元素
    pq.push(3);
    pq.push(1);
    pq.push(2);

    // 输出队列中的元素数量
    std::cout << "Size: " << pq.size() << std::endl;

    // 输出优先级最高的元素
    std::cout << "Top: " << pq.top() << std::endl;

    // 移除优先级最高的元素
    pq.pop();

    // 再次输出优先级最高的元素
    std::cout << "Top after pop: " << pq.top() << std::endl;

    return 0;
}    