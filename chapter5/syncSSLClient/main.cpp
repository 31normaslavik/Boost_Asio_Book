#include "suncsslclient.h"

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <iostream>

using namespace boost;

int main() {
  const std::string raw_ip_address = "127.0.0.1";
  const unsigned short port_num = 3333;

  try {
    SyncSSLClient client(raw_ip_address, port_num);

    // Sync connect.
    client.connect();

    std::cout << "Sending request to the server... " << std::endl;

    std::string response = client.emulate_long_computation_op(10);

    std::cout << "Response received: " << response << std::endl;

    // Close the connection and free resources.
    client.close();
  } catch (system::system_error &e) {
    std::cout << "Error occured! Error code = " << e.code()
              << ". Message: " << e.what();

    return e.code().value();
  }

  return 0;
}
