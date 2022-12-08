#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <chrono>

#define PORT 8080

using namespace std;


class ServerSocket {
    private:
        string nome;
        
    public:
        // Constructor:
        ServerSocket();
        
        // Destructor
        virtual ~ServerSocket();
    
    
        int server_fd, new_socket, valread;
        int setsockopt_status, bind_status;
        struct sockaddr_in address;
        int opt = 1;
        int addrlen = sizeof(address);
        char buffer[1024]{0};

        time_t local_time;

        char msg[1024]{0};


        int configureSocket();

        int listenToConnections();
};