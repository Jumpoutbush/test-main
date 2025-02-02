// 一个map里存储enum和对应的call_back函数
#include <iostream>
#include <functional>
#include <map>
#include <vector>
#include <limits>

enum ecall{
    insert_sort = 1,
    bubble_sort = 2
};

std::map <int, std::function<void(std::vector<int>& vec)>> handlers;

void _handle_emplace(){
    handlers.emplace(insert_sort, [&](std::vector<int>& vec){
        if(vec.size() <= 1) return;

        for(size_t i = 1; i < vec.size() - 1; ++i){
            int temp = vec[i];
            size_t j = i;
            while(vec[j - 1] > temp && j > 0){
                vec[j] = vec[j - 1];
                j--;
            }
            vec[j] = temp;
        }
        vec.pop_back();
        for(const auto& element : vec){
            std::cout << element << " ";
        }
    });
    handlers.emplace(bubble_sort, [&](std::vector<int>& vec){
        if(vec.size() <= 1) return;
        int n = vec.size();
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(vec[j] <= vec[i]){
                    int temp = vec[j];
                    vec[j] = vec[i];
                    vec[i] = temp;
                }
            }
        }
        for(const auto& element : vec){
            std::cout << element << " ";
        }
    });
}

int main()
{
    std::vector<int> vec = {3,4,6,7,8,9,1,2,10,5};
    int MAX = 10;
    _handle_emplace();
    // auto it = handlers.find(insert_sort);
    auto it = handlers.find(bubble_sort);
    if(it != handlers.end()){
        it->second(vec);
    }

    return 0;
}