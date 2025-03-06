#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
// 定义双向链表节点结构
struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int capacity;
    int size;
    std::unordered_map<int, DLinkedNode*> cache;
    DLinkedNode* head;
    DLinkedNode* tail;

    // 删除节点
    void removeNode(DLinkedNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // 添加节点到链表头部
    void addToHead(DLinkedNode* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    // 删除尾部节点
    DLinkedNode* removeTail() {
        DLinkedNode* node = tail->prev;
        removeNode(node);
        return node;
    }

    // 将节点移动到链表头部
    void moveToHead(DLinkedNode* node) {
        removeNode(node);
        addToHead(node);
    }


public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->size = 0;
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        }
        DLinkedNode* node = cache[key];
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            DLinkedNode* node = cache[key];
            node->value = value;
            moveToHead(node);
        } else {
            DLinkedNode* node = new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            ++size;
            if (size > capacity) {
                DLinkedNode* removed = removeTail();
                cache.erase(removed->key);
                delete removed;
                --size;
            }
        }
    }

    // 析构函数，释放链表节点内存
    ~LRUCache() {
        DLinkedNode* current = head;
        while (current) {
            DLinkedNode* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};


// 测试函数
std::vector<int> testLRUCache(const std::vector<std::string>& operations, const std::vector<std::vector<int>>& params) {
    std::vector<int> results;
    LRUCache* cache = nullptr;

    for (size_t i = 0; i < operations.size(); ++i) {
        if (operations[i] == "LRUCache") {
            cache = new LRUCache(params[i][0]);
            results.push_back(-2); // 用 -2 表示创建操作，在输出中可忽略
        } else if (operations[i] == "put") {
            cache->put(params[i][0], params[i][1]);
            results.push_back(-2); // 用 -2 表示 put 操作，在输出中可忽略
        } else if (operations[i] == "get") {
            int result = cache->get(params[i][0]);
            results.push_back(result);
        }
    }

    delete cache;
    return results;
}

int main() {
    std::vector<std::string> operations = {"LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"};
    std::vector<std::vector<int>> params = {{2}, {1, 1}, {2, 2}, {1}, {3, 3}, {2}, {4, 4}, {1}, {3}, {4}};

    std::vector<int> results = testLRUCache(operations, params);

    std::cout << "[";
    for (size_t i = 0; i < results.size(); ++i) {
        if (i > 0) {
            std::cout << ", ";
        }
        if (results[i] == -2) {
            std::cout << "null";
        } else {
            std::cout << results[i];
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}