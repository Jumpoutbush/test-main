#include <iostream>
#include <thread>
#include <windows.h>

void foo()
{
	std::cout << "Run New thread!\n";
	Sleep(2000);   		//需要头文件<windows.h>
}

int main()
{
	std::thread t(foo);

	if (t.joinable())
	{
		//t.join();  		// 等待线程t执行完毕

		t.detach();  // 分离线程t与主线程
	}

	std::cout << "Run Main thread!\n";
	return 0;
}
