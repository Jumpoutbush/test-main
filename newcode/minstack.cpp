#include <stack>
#include <climits>
#include <cassert>
#include <bits/stdc++.h>

class MinStack {
private:
    std::stack<int> x_stack; //  Stack to store all the elements of the MinStack
    std::stack<int> min_stack; //  Stack to store the minimum elements corresponding to each element in x_stack
public:
    MinStack() {
        min_stack.push(INT_MAX);
    }
    
    void push(int x) {
        x_stack.push(x);
        min_stack.push(std::min(min_stack.top(), x));
    }
    
    void pop() {
        x_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return x_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
    }
};

int main() {
    MinStack* obj = new MinStack();
    obj->push(2);
    obj->push(0);
    std::cout << obj->top() << std::endl; // 0
    std::cout << obj->getMin() << std::endl; // 0
    obj->pop();
    std::cout << obj->top() << std::endl; // 2
    std::cout << obj->getMin() << std::endl; // 2
    delete obj;
    getchar();
    return 0;
}
