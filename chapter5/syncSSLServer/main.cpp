#include "server.h"

#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>

#include <atomic>
#include <iostream>
#include <thread>

using namespace boost;

int main() {

  unsigned short port_num = 3333;

  try {
    Server srv;
    srv.start(port_num);

    std::this_thread::sleep_for(std::chrono::seconds(60));

    srv.stop();
  } catch (system::system_error &e) {
    std::cerr << "Error occured! Error code = " << e.code()
              << ". Message: " << e.what() << std::endl;
  }

  return 0;
}
