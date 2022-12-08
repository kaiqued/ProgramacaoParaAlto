// Client side C/C++ program to demonstrate Socket programming
#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <thread>
#include <chrono>
#define PORT 8080

int main()
{
    int sock = 0, valread, client_fd, valid_addr;
    struct sockaddr_in serv_addr;
    char cmd[]{"time"};
    char buffer[1024] = {0};

    // Creating socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        std::cout << "\033[1;31mError:\033[0m Socket failed" << std::endl;
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    valid_addr = inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
    if (valid_addr <= 0)
    {
        std::cout << "\033[1;31mError:\033[0m Invalid address. Address not supported" << std::endl;
        return -1;
    }

    // Creating socket file descriptor
    client_fd = connect(sock, reinterpret_cast<sockaddr *>(&serv_addr), sizeof(serv_addr));
    if (client_fd < 0)
    {
        std::cout << "\033[1;31mError:\033[0m Connection Failed" << std::endl;
        return -1;
    }
    else
    {
        std::cout << "\033[1;32mConnection:\033[0m Connected to " << inet_ntoa(serv_addr.sin_addr) << std::endl;
    }

    for (int i{0}; i < 6; ++i)
    {
        // Send command
        std::cout << "Send to " << inet_ntoa(serv_addr.sin_addr) << ": \"" << cmd << "\"" << std::endl;
        send(sock, cmd, strlen(cmd), 0);
        valread = read(sock, buffer, 1024);
        if (valread > 0)
        {
            std::cout << "Received from " << inet_ntoa(serv_addr.sin_addr) << ": \"" << buffer << "\"" << std::endl;
        }

        // Sleep for 2s
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    // closing the connected socket
    close(client_fd);
    std::cout << "\033[1;32mDisconnected\033[0m" << std::endl;

    return 0;
}