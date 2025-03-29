#include <iostream>
#include <vector>
#include <functional>

std::vector<int> v;
void push_back_sum(int a, int b) {
    v.push_back(a + b);
}

int main() {
    // Binding print_sum function with arguments 2 and 3
    auto binded_func = std::bind(push_back_sum, 2, 3);
    // Calling the bound function
    binded_func();  // Outputs: 5
    for(auto& i : v){
        std::cout << i << " ";
    }
    getchar();
    return 0;
}
