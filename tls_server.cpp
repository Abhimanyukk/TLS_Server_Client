#include <iostream>

#include "tls.hpp"

int main()
{
    std::cout << "This is a TLS Server Application" << std::endl;

    tls_connection::TLS();

    return 0;
}