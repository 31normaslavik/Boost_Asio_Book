#include <boost/asio.hpp>
#include <iostream>
#include <string>

//using namespace std;
//using namespace boost;

int main()
{
    // Step 1. Assume that the client application has already
    // obtained the IP-address and the protocol port number.
    std::string raw_ip_address{"127.0.0.1"};
    unsigned short port_num{3333};

    // Used to store information about error that happens
    // while parsing the raw IP-address.
    std::cout << "Hello World!" << std::endl;
    boost::system::error_code ec;

    // Step 2. Using IP protocol version independent address
    // representation.
    boost::asio::ip::address ip_address{boost::asio::ip::address::from_string(raw_ip_address, ec)};

    if (ec.value() != 0) {
        // Provided IP address is invalid. Breaking execution.
        std::cout << "Failed to parse the IP address. Error code = " << ec.value()
                  << ". Message: " << ec.message();
        return ec.value();
    }

    // Step 3.
    boost::asio::ip::tcp::endpoint ep{ip_address, port_num};

    // Step 4. The endpoint is ready and can be used to specify a
    // particular server in the network the client wants to
    // communicate with.

    return 0;
}
