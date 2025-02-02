#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <future>

const char* SERVER_IP = "127.0.0.1";
const int PORT = 8080;
const int BUFFER_SIZE = 1024;

// 异步读取服务器响应的函数
void receiveMessages(int sock) {
    char buffer[BUFFER_SIZE] = {0};
    while (true) {
        auto readFuture = std::async(std::launch::async, [sock, buffer]() mutable{
            ssize_t valread = read(sock, static_cast<void*>(buffer), BUFFER_SIZE);
            if (valread <= 0) {
                return false; // 服务器断开连接
            }
            std::cout << "Received from server: " << buffer << std::endl;
            return true;
        });

        if (!readFuture.get()) {
            break;
        }
    }
}

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};

    // 创建套接字
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        std::cout << "\n Socket creation error \n";
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // 将 IPv4 地址从文本转换为二进制形式
    if (inet_pton(AF_INET, SERVER_IP, &serv_addr.sin_addr) <= 0) {
        std::cout << "\nInvalid address/ Address not supported \n";
        return -1;
    }

    // 连接到服务器
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cout << "\nConnection Failed \n";
        return -1;
    }

    std::cout << "Connected to server" << std::endl;

    // 异步接收服务器消息
    std::async(std::launch::async, receiveMessages, sock);

    // 发送消息给服务器
    while (true) {
        std::string message;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // 清空输入缓冲区
        std::getline(std::cin, message);
        if (message == "exit") {
            break;
        }
        send(sock, message.c_str(), message.length(), 0);
    }

    close(sock);
    return 0;
}