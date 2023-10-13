#ifndef TLS_HPP
#define TLS_HPP

#include <openssl/ssl.h>
#include <openssl/err.h>

#include "socket.hpp"

namespace tls_connection
{
    class TLS : protected Socket
    {
    private:
        SSL_CTX *ctx;

    public:
        TLS(int port = 443);
        ~TLS();
    };
}

#endif /* TLS_HPP */
