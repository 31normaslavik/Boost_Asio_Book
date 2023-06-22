#pragma once

#include <boost/asio/ip/tcp.hpp>
#include <memory>

class Service {
  public:
  Service() {}

  void StartHandligClient(std::shared_ptr<boost::asio::ip::tcp::socket> sock);

  private:
  void HandleClient(std::shared_ptr<boost::asio::ip::tcp::socket> sock);
};
