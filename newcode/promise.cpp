#include <iostream>
#include <thread>
#include <future>
#include <chrono>

std::string fetchDataFromDB(std::string query){
    return "Data is " + query;
}

// set data into promise, and fetch it in the main thread
int setData(std::promise<int> promise){
    try{
        std::this_thread::sleep_for(std::chrono::seconds(1));
        promise.set_value(42);
    }catch(...){
        promise.set_exception(std::current_exception());
    }
}
int main()
{
    std::future<std::string> resultFromDB = std::async(std::launch::async, fetchDataFromDB, "query");
    
    {
        // do something else
        std::promise<int> promise;
        std::future<int> future = promise.get_future();
        std::thread t(setData, std::move(promise));
        std::cout << "value is " << future.get() << std::endl;
        t.join();
    }

    std::string dbData = resultFromDB.get();
    std::cout << dbData << std::endl;

    getchar();
    return 0;

}