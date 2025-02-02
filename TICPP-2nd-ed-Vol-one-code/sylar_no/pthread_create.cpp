#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void* thread_function(void* arg) {
    printf("Thread is running\n");
    return (void*)42;  // 返回值可通过 pthread_join 获取
}

int main() {
    pthread_t thread;
    int ret;
    void* retval;

    // 创建一个新线程
    ret = pthread_create(&thread, NULL, thread_function, NULL);
    if (ret) {
        printf("Error creating thread\n");
        return 1;
    }

    // 等待线程结束
    ret = pthread_join(thread, &retval);
    if (ret) {
        printf("Error joining thread\n");
        return 1;
    }

    // 输出线程返回值
    printf("Thread exited with return value %ld\n", retval);
    
    return 0;
}
