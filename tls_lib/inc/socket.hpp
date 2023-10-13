#ifndef SOCKET_HPP
#define SOCKET_HPP

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

namespace tls_connection
{
    class Client
    {
    private:
        int fd;

    public:
        Client(int conn);
        size_t Read(char *pData);
        size_t Write(const char *pData, size_t len);
    };

    class Socket
    {
    private:
        int server;

    public:
        Socket(int port = 5026);
        ~Socket();
        Client AcceptConnection();
    };
}

#endif /* SOCKET_HPP */