#include <iostream>
#include <windows.h>

#define SHARED_MEMORY_NAME L"MySharedMemory"
#define SHARED_MEMORY_SIZE 1024

int main() {
    // 创建共享内存对象
    HANDLE hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE,    // 使用页面文件而不是文件
        NULL,                    // 默认安全属性
        PAGE_READWRITE,          // 可读可写
        0,                       // 高 32 位的大小
        SHARED_MEMORY_SIZE,      // 低 32 位的大小
        SHARED_MEMORY_NAME       // 共享内存对象的名称
    );

    if (hMapFile == NULL) {
        std::cerr << "CreateFileMapping failed: " << GetLastError() << std::endl;
        return 1;
    }

    // 将共享内存对象映射到进程的地址空间
    LPVOID pBuf = MapViewOfFile(
        hMapFile,                // 共享内存对象的句柄
        FILE_MAP_ALL_ACCESS,     // 读写访问
        0,                       // 高 32 位的偏移量
        0,                       // 低 32 位的偏移量
        SHARED_MEMORY_SIZE       // 映射的大小
    );

    if (pBuf == NULL) {
        std::cerr << "MapViewOfFile failed: " << GetLastError() << std::endl;
        CloseHandle(hMapFile);
        return 1;
    }

    // 写入数据到共享内存
    const char* message = "Hello, shared memory!";
    memcpy(pBuf, message, strlen(message) + 1);

    // 解除映射
    UnmapViewOfFile(pBuf);

    // 关闭共享内存对象的句柄
    CloseHandle(hMapFile);

    return 0;
}