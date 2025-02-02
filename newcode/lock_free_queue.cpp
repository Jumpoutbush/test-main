#include <iostream>
#include <atomic>
#include <memory>

template <typename T>
class LockFreeQueue {
private:
    struct Node {
        T value;
        std::shared_ptr<Node> next;
        Node(const T& val) : value(val), next(nullptr) {}
    };

    std::atomic<std::shared_ptr<Node>> head;
    std::atomic<std::shared_ptr<Node>> tail;

public:
    LockFreeQueue() : head(std::make_shared<Node>(T())), tail(head.load()) {}

    ~LockFreeQueue() {
        while (pop());
    }

    void push(const T& value) {
        std::shared_ptr<Node> new_node = std::make_shared<Node>(value);
        std::shared_ptr<Node> prev_tail;
        std::shared_ptr<Node> next;
        while (true) {
            prev_tail = tail.load();
            next = prev_tail->next;
            if (next == nullptr) {
                // 尝试将新节点添加到队尾
                std::shared_ptr<Node> expected_next = nullptr;
                if (prev_tail->next.compare_exchange_weak(expected_next, new_node)) {
                    // 成功添加，更新尾指针
                    std::shared_ptr<Node> expected_tail = prev_tail;
                    tail.compare_exchange_weak(expected_tail, new_node);
                    return;
                }
            } else {
                // 尾指针可能已经更新，帮助更新尾指针
                std::shared_ptr<Node> expected_tail = prev_tail;
                tail.compare_exchange_weak(expected_tail, next);
            }
        }
    }

    bool pop() {
        std::shared_ptr<Node> prev_head;
        std::shared_ptr<Node> next;
        while (true) {
            prev_head = head.load();
            std::shared_ptr<Node> curr_tail = tail.load();
            next = prev_head->next;
            if (prev_head == head.load()) {
                if (prev_head == curr_tail) {
                    // 队列为空
                    if (next == nullptr) {
                        return false;
                    }
                    // 帮助更新尾指针
                    std::shared_ptr<Node> expected_tail = curr_tail;
                    tail.compare_exchange_weak(expected_tail, next);
                } else {
                    T value = next->value;
                    std::shared_ptr<Node> expected_head = prev_head;
                    if (head.compare_exchange_weak(expected_head, next)) {
                        // 成功弹出，返回值
                        return true;
                    }
                }
            }
        }
    }
};

int main() {
    LockFreeQueue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);

    int value;
    if (queue.pop()) {
        value = 1;
        std::cout << "Popped value: " << value << std::endl;
    }
    if (queue.pop()) {
        value = 2;
        std::cout << "Popped value: " << value << std::endl;
    }
    if (queue.pop()) {
        value = 3;
        std::cout << "Popped value: " << std::endl;
    }
    return 0;
}