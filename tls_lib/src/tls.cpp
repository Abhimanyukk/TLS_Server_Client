#include "tls.hpp"

tls_connection::TLS::TLS(int port) : Socket(port)
{
    SSL_library_init();
    OpenSSL_add_all_algorithms();
    SSL_load_error_strings();

    this->ctx = SSL_CTX_new(TLS_server_method());

    // Client client = this->AcceptConnection();
}

tls_connection::TLS::~TLS()
{
}
