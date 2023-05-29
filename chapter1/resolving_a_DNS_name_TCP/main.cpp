#include <boost/asio.hpp>
#include <iostream>
#include <string>

// using namespace std;
// using namespace boost;

int main(int argc, char **argv)
{
    // Step 1. Assume that the client application has already
    // obtained the DNS name and protocol port number and
    // represented them as strings.
    if (argc < 3)
        throw std::runtime_error("[host] [port]");

    std::string host = argv[1];
    std::string port_num = argv[2];

    // Step 2.
    boost::asio::io_service ios;

    // Step 3. Creating a query.
    boost::asio::ip::tcp::resolver::query
        resolver_query(host, port_num, boost::asio::ip::tcp::resolver::query::numeric_service);

    // Step 4. Creating a resolver.
    boost::asio::ip::tcp::resolver resolver(ios);

    // Used to store information about error that happens
    // during the resolution process.
    boost::system::error_code ec;

    // Step 5.
    boost::asio::ip::tcp::resolver::iterator it = resolver.resolve(resolver_query, ec);
    boost::asio::ip::tcp::resolver::iterator it_end;

    // Handling errors if any.
    if (ec.value() != 0) {
        // Failed to resolve the DNS name. Breaking execution.
        std::cout << "Failed to resolve a DNS name."
                  << "Error code = " << ec.value() << ". Message = " << ec.message();
        return ec.value();
    }

    for (; it != it_end; ++it)
        //std::cout << it->endpoint().address() << " " << it->endpoint().port() << std::endl;

        boost::asio::ip::tcp::endpoint ep = it->endpoint();

    //    std::cout << it->host_name() << std::endl;
    //    std::cout << it->service_name() << std::endl;
    //    std::cout << it->endpoint().address() << std::endl;

    return 0;
}
