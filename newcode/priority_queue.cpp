#include <algorithm>
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// 大根堆
template <typename T>
class priority_queue : public enable_shared_from_this<priority_queue<T>>{
private:
    vector<T> data;
    void siftUp(int index){
        while(index > 0){
            int parent = (index - 1) / 2;
            if(data[parent] >= data[index]){
                break;
            }
            swap(data[parent], data[index]);
            index = parent;
        }
    }

    void siftDown(int index){
        int largest = index;
        int left = largest * 2 + 1;
        int right = largest * 2 + 2;

        if(left < data.size() && data[left] > data[largest]){
            largest = left;
        }
        if(right < data.size() && data[right] > data[largest]){
            largest = right;
        }
        if(largest != index){
            swap(data[largest], data[index]);
            siftDown(largest);
        }
    }
public:
    void push(const T& value){
        data.push_back(value);
        siftUp(data.size() - 1);
    }
    void pop(){
        if(data.empty()){
            return;
        }
        swap(data[0], data.back());
        data.pop_back();
        siftDown(0);
    }
    T top() const {
        if (data.empty()) {
            throw std::out_of_range("Priority queue is empty");
        }
        return data[0];
    }

    bool empty() const {
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }

    void print(){
        for(auto& i : data){
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    shared_ptr<priority_queue<int>> pq = make_shared<priority_queue<int>>();
    cout << pq.use_count() << endl;
    pq->push(3);
    pq->push(1);
    pq->push(4);
    pq->print();
    pq->push(1);
    pq->push(5);
    pq->push(9);
    pq->print();
    system("pause");
    return 0;
}    