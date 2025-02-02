#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <future>

const int PORT = 8080;
const int BUFFER_SIZE = 1024;

// 处理客户端连接的函数
void handleClient(int clientSocket) {
    char buffer[BUFFER_SIZE] = {0};
    while (true) {
        // 异步读取客户端数据
        auto readFuture = std::async(std::launch::async, [clientSocket, buffer]() mutable {
            // 显式类型转换
            ssize_t valread = read(clientSocket, static_cast<void*>(buffer), BUFFER_SIZE);
            if (valread <= 0) {
                return false; // 客户端断开连接
            }
            std::cout << "Received from client: " << buffer << std::endl;
            return true;
        });

        if (!readFuture.get()) {
            break;
        }
    }
    close(clientSocket);
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    // 创建套接字
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // 设置套接字选项
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // 绑定套接字
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    // 监听连接
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    std::cout << "Server listening on port " << PORT << std::endl;

    while (true) {
        // 接受客户端连接
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            continue;
        }
        std::cout << "New client connected" << std::endl;

        // 异步处理客户端连接
        std::async(std::launch::async, handleClient, new_socket);
    }

    close(server_fd);
    return 0;
}