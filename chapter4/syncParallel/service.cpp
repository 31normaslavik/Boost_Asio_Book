#include "service.h"

#include <boost/asio/read_until.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/asio/write.hpp>
#include <boost/system/system_error.hpp>
#include <iostream>
#include <thread>

void Service::StartHandligClient(
    std::shared_ptr<boost::asio::ip::tcp::socket> sock) {
  std::thread th(([this, sock]() { HandleClient(sock); }));

  th.detach();
}

void Service::HandleClient(std::shared_ptr<boost::asio::ip::tcp::socket> sock) {
  try {
    boost::asio::streambuf request;
    boost::asio::read_until(*sock.get(), request, '\n');

    // Emulate request processing.
    int i = 0;
    while (i != 1000000)
      i++;

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    // Sending response.
    std::string response = "Response\n";
    boost::asio::write(*sock.get(), boost::asio::buffer(response));
  } catch (boost::system::system_error &e) {
    std::cerr << "Error occured! Error code = " << e.code()
              << ". Message: " << e.what() << std::endl;
  }

  // Clean-up.
  delete this;
}
