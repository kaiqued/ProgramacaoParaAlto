
#include "ClassServer.h"

ServerSocket::ServerSocket(){
}


ServerSocket::~ServerSocket(){
    // closing the connected socket
    close(new_socket);
    // closing the listening socket
    shutdown(server_fd, SHUT_RDWR);

    std::cout << "\033[1;32mDisconnected\033[0m" << std::endl;
}


int ServerSocket::configureSocket(){
    // Creating socket file descriptor
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0)
    {
        std::cout << "\033[1;31mError:\033[0m Socket failed" << std::endl;
        return -1;
    }
    // Configure socket
    setsockopt_status = setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));
    if (setsockopt_status < 0)
    {
        std::cout << "\033[1;31mError:\033[0m Setsockopt failed" << std::endl;
        return -1;
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Attaching socket to INADDR_ANY at the port 8080
    bind_status = bind(server_fd, reinterpret_cast<sockaddr *>(&address), sizeof(address));
    if (bind_status < 0)
    {
        std::cout << "\033[1;31mError:\033[0m Bind failed" << std::endl;
        return -1;
    }
}


int ServerSocket::listenToConnections(){
    // Listening to new connections
    if (listen(server_fd, 3) < 0)
    {
        std::cout << "\033[1;31mError:\033[0m Client listen failed" << std::endl;
        return -1;
    }
    else
    {
        std::cout << "\033[1;32mListening:\033[0m Accepting new connections " << std::endl;
    }

    new_socket = accept(server_fd, reinterpret_cast<sockaddr *>(&address), reinterpret_cast<socklen_t *>(&addrlen));
    if (new_socket < 0)
    {
        std::cout << "\033[1;31mError:\033[0m Client accept failed" << std::endl;
        return -1;
    }
    else
    {
        std::cout << "\033[1;32mConnection:\033[0m Connection from " << inet_ntoa(address.sin_addr) << std::endl;
    }

    // Main loop
    do
    {
        valread = read(new_socket, buffer, 1024); // Read data from new_socket

        if (valread)
        {
            std::cout << "Received from " << inet_ntoa(address.sin_addr) << ": \"" << buffer << "\"" << std::endl;
        }

        if (strcmp(buffer, "time") == 0 && valread > 0)
        { // Service to send time
            // Prepare time message
            local_time = std::time(nullptr);
            strcpy(msg, std::ctime(&local_time));
            strtok(msg, "\n"); // Remove "\n"

            // Send local time
            std::cout << "Send to " << inet_ntoa(address.sin_addr) << ": \"" << msg << "\"" << std::endl;
            send(new_socket, msg, strlen(msg), 0);
        }
    } while (valread);

}
