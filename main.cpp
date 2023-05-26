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

    return 0;
}
