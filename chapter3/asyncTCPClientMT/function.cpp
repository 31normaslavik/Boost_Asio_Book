#include "function.h"
#include <boost/asio/error.hpp>
#include <iostream>

void handler(unsigned int request_id, const std::string& response,
             const boost::system::error_code& ec) {
  if (ec.value() == 0) {
    std::cout << "Request #" << request_id
              << " has completed. Response: " << response << std::endl;
  } else if (ec == boost::asio::error::operation_aborted) {
    std::cout << "Request #" << request_id << " has been cancelled by the user."
              << std::endl;
  } else {
    std::cout << "Request #" << request_id
              << " failed! Error code = " << ec.value()
              << ". Error message = " << ec.message() << std::endl;
  }

  return;
}
