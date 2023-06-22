#pragma once

#include <boost/asio/ip/tcp.hpp>

class Service {
  public:
  Service() {}

  void HandleClient(boost::asio::ip::tcp::socket &sock);
};
