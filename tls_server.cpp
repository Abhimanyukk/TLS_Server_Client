#include <iostream>
// #include <openssl/ssl.h>
// #include <openssl/err.h>

#include "socket.hpp"

int main()
{
    std::cout << "This is a TLS Server Application" << std::endl;

    lib_socket::Socket sock;
    lib_socket::Client client = sock.AcceptConnection();
    while (true)
    {
        char pData[100] = {0};
        int len = client.Read(pData);
        if (len <= 0)
        {
            std::cout << "Client connection interrupted" << std::endl;
            break;
        }
        std::cout << len << " bytes received" << std::endl;
        std::cout << "Data received: " << pData << std::endl;

        std::string response = "Hello from server";
        client.Write(response.c_str(), response.length());
    }

    return 0;
}