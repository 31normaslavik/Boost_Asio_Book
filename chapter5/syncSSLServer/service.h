#pragma once

#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/read_until.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/system/system_error.hpp>
#include <iostream>
#include <thread>

class Service {
  public:
  Service() {}

  void handle_client(
      boost::asio::ssl::stream<boost::asio::ip::tcp::socket>& ssl_stream);
};
