#include <iostream>
#include <chrono>
#include <future>
#include <thread>
#include <functional>
int mytask(int a, int b){
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return a + b;
}
void set_value(std::promise<int>& prom, int a, int b){
    std::this_thread::sleep_for(std::chrono::seconds(2));
    prom.set_value(a + b);
}
void use_package(){
    std::packaged_task<int(int, int)> task(mytask);
    std::future<int> res = task.get_future();
    std::thread t(std::move(task), 1, 4);
    t.join();
    int val = res.get();
    std::cout << val << std::endl;
}

void use_promise(){
    std::promise<int> prom;
    std::future<int> fut = prom.get_future();
    std::thread t(set_value, std::ref(prom), 2, 8);
    t.join();
    int val = fut.get();
    std::cout << val << std::endl;
}
int main()
{
    use_package();
    use_promise();
    system("pause");
    return 0;
}