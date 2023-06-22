#include "service.h"
#include <boost/asio/read_until.hpp>
#include <boost/asio/write.hpp>
#include <iostream>
#include <thread>

Service::Service(std::shared_ptr<boost::asio::ip::tcp::socket> sock)
    : m_sock(sock) {}

void Service::StartHandling() {

  boost::asio::async_read_until(*m_sock.get(), m_request, '\n',
                                [this](const boost::system::error_code& ec,
                                       std::size_t bytes_transferred) {
                                  onRequestReceived(ec, bytes_transferred);
                                });
}

void Service::onRequestReceived(const boost::system::error_code& ec,
                                std::size_t bytes_transferred) {
  if (ec.value() != 0) {
    std::cout << "Error occured! Error code = " << ec.value()
              << ". Message: " << ec.message();

    onFinish();
    return;
  }

  // Process the request.
  m_response = ProcessRequest(m_request);

  // Initiate asynchronous write operation.
  boost::asio::async_write(*m_sock.get(), boost::asio::buffer(m_response),
                           [this](const boost::system::error_code& ec,
                                  std::size_t bytes_transferred) {
                             onResponseSent(ec, bytes_transferred);
                           });
}

void Service::onResponseSent(const boost::system::error_code& ec,
                             std::size_t bytes_transferred) {
  if (ec.value() != 0) {
    std::cout << "Error occured! Error code = " << ec.value()
              << ". Message: " << ec.message();
  }

  onFinish();
}

std::string Service::ProcessRequest(boost::asio::streambuf& request) {

  // In this method we parse the request, process it
  // and prepare the request.

  // Emulate CPU-consuming operations.
  int i = 0;
  while (i != 1000000)
    i++;

  // Emulate operations that block the thread
  // (e.g. synch I/O operations).
  std::this_thread::sleep_for(std::chrono::milliseconds(100));

  // Prepare and return the response message.
  std::string response = "Response\n";
  return response;
}
