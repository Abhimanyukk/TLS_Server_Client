#include "socket.hpp"

tls_connection::Socket::Socket(int port)
{
    std::cout << "Server starting..." << std::endl;

    this->server = socket(AF_INET, SOCK_STREAM, 0);
    if (this->server < 0)
    {
        throw std::runtime_error("Socket creation failed");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);

    if (bind(this->server, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        throw std::runtime_error("Socket binding failed");
    }

    if (listen(this->server, 1) < 0)
    {
        throw std::runtime_error("Socket Listen failed");
    }

    std::cout << "Socket created" << std::endl;
}

tls_connection::Socket::~Socket()
{
    std::cout << "Server destructor" << std::endl;
}

tls_connection::Client tls_connection::Socket::AcceptConnection()
{
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    std::cout << "Server waiting for connection..." << std::endl;
    int conn = accept(this->server, (struct sockaddr *)&client_addr, &client_len);
    if (conn < 0)
    {
        return 0;
    }
    Client client(conn);

    return client;
}

tls_connection::Client::Client(int conn)
{
    this->fd = conn;
    std::cout << "Client connected" << std::endl;
}

size_t tls_connection::Client::Read(char *pData)
{
    return read(this->fd, pData, 1024);
}

size_t tls_connection::Client::Write(const char *pData, size_t len)
{
    return write(this->fd, pData, len);
}