#include <boost/asio.hpp>
#include <iostream>
#include <string>

// using namespace std;
// using namespace boost;

int main()
{
    // Step 1. Here we assume that the server application has
    // already obtained the protocol port number.
    unsigned short port_num = 3333;

    // Step 2. Creating an endpoint.
    boost::asio::ip::tcp::endpoint ep(boost::asio::ip::address_v4::any(), port_num);

    // Used by 'acceptor' class constructor.
    boost::asio::io_context ios;

    // Step 3. Creating and opening an acceptor socket.
    boost::asio::ip::tcp::acceptor acceptor(ios, ep.protocol());
    boost::system::error_code ec;

    // Step 4. Binding the acceptor socket.
    acceptor.bind(ep, ec);

    // Handling errors if any.
    if (ec.value() != 0) {
        // Failed to bind the acceptor socket. Breaking
        // execution.
        std::cout << "Failed to bind the acceptor socket."
                  << "Error code = " << ec.value() << ". Message: " << ec.message();
        return ec.value();
    }
    return 0;
}
