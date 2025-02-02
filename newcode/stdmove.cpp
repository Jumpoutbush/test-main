#include <iostream>
#include <utility>
#include <string>
int main()
{
    std::string s1 = "Hello";
    std::string s2 = std::move(s1);

    std::cout << "s1: " << s1 << "\n"; // s1 可能为空（未定义）
    std::cout << "s2: " << s2 << "\n"; // s2 拥有资源
    system("pause");
    return 0;
}
