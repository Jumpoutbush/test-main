#include <iostream>
#include <thread>    //必须包含<thread>头文件

void threadFunctionA()
{
	std::cout << "Run New thread: 1" << std::endl;
}
void threadFunctionB(int n)
{
	std::cout << "Run New thread: "<< n << std::endl;
}

int main()
{
	std::cout << "Run Main Thread" << std::endl;

	std::thread newThread1(threadFunctionA);
	std::thread newThread2(threadFunctionB,2);

	newThread1.join();
	newThread2.join();

	return 0;
}
