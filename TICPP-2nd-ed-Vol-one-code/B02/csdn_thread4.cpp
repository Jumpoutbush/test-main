#include <iostream>
#include <thread>
#include <chrono>

void my_thread()
{
	std::cout << "Thread " << std::this_thread::get_id() << " start!" << std::endl;

	for (int i = 1; i <= 5; i++)
	{
		std::cout << "Thread " << std::this_thread::get_id() << " running: " << i << std::endl;
		//std::this_thread::yield();	// 让出当前线程的时间片
		std::this_thread::sleep_for(std::chrono::milliseconds(200));  // 线程休眠200毫秒
	}

	std::cout << "Thread " << std::this_thread::get_id() << " end!" << std::endl;
}

int main()
{
	std::cout << "Main thread id: " << std::this_thread::get_id() << std::endl;
	
    std::thread t1(my_thread);
	std::thread t2(my_thread);
	
	t1.join();
	t2.join();
    system("pause");
	return 0;
}
