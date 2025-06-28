#include <iostream>
#include <vector>
#include <unordered_map>
#include <cassert>
using namespace std;
struct DLinkedNode{
    int key, value;
    DLinkedNode* next;
    DLinkedNode* prev;
    DLinkedNode():key(0), value(0), next(nullptr), prev(nullptr){}
    DLinkedNode(int key_, int value_):key(key_), value(value_), next(nullptr), prev(nullptr){}
};

class LRUCache{
private:
    int capacity;
    int size;
    DLinkedNode* head;
    DLinkedNode* tail;
    unordered_map<int, DLinkedNode*> cache;

    void removeNode(DLinkedNode* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToHead(DLinkedNode* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }
    DLinkedNode* removeTail(){
        auto node = tail->prev;
        removeNode(node);
        return node;
    }
    void moveToHead(DLinkedNode* node){
        removeNode(node);
        addToHead(node);
    }
public:
    LRUCache(int capacity){
        this->capacity = capacity;
        size = 0;
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    ~LRUCache(){
        DLinkedNode* cur = head;
        while(cur){
            DLinkedNode* nextnode = cur->next;
            delete cur;
            cur = nextnode;
        }
    }
    int get(int key){
        if(cache.find(key) == cache.end()){
            return -1;
        }
        DLinkedNode* cur = cache[key];
        moveToHead(cur);
        return cur->value;
    }
    void put(int key, int value){
        if(cache.find(key) != cache.end()){
            auto cur = cache[key];
            cur->value = value;
            moveToHead(cur);
        }else{
            DLinkedNode* node = new DLinkedNode(key, value);
            cache[key] = node;
            addToHead(node);
            size ++;
            if(size > capacity){
                DLinkedNode* del = removeTail();
                cache.erase(del->key);
                delete del;
                size --;
            }
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
    system("pause");
    return 0;
}