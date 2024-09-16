#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int num = 0;

void thread_function(int &n)
{
	for (int i = 0; i < 100; ++i)
	{
		mtx.lock();
		n++;
		mtx.unlock();
	}
}

int main()
{
	std::thread myThread[500];
	for (std::thread &a : myThread)
	{
		a = std::thread(thread_function, std::ref(num));
		a.join();
	}

	std::cout << "num = " << num << std::endl;
	std::cout << "Main thread exits!" << std::endl;
	return 0;
}
