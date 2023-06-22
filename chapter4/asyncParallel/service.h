#pragma once

#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/system/error_code.hpp>
#include <memory>

class Service {
  public:
  Service(std::shared_ptr<boost::asio::ip::tcp::socket> sock);

  void StartHandling();

  private:
  void onRequestReceived(const boost::system::error_code &ec,
                         std::size_t bytes_transferred);

  void onResponseSent(const boost::system::error_code &ec,
                      std::size_t bytes_transferred);

  // Here we perform the cleanup.
  void onFinish() { delete this; }

  std::string ProcessRequest(boost::asio::streambuf &request);

  private:
  std::shared_ptr<boost::asio::ip::tcp::socket> m_sock;
  std::string m_response;
  boost::asio::streambuf m_request;
};
