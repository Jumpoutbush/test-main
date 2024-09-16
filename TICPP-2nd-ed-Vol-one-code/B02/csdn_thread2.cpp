//执行函数有引用参数
#include <iostream>
#include <thread>    //必须包含<thread>头文件

void threadFunc(int &arg1, int arg2)
{
	arg1 = arg2;
	std::cout << "arg1 = " << arg1 << std::endl;
}

int main()
{
    std::cout << "Run Main Thread!" << std::endl;
	int a = 1;
	int b = 5;
	std::thread newTh(threadFunc, std::ref(a), b);//thread传右值
	newTh.join();
	return 0;
}
