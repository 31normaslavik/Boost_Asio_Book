#pragma once
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <string>

class SyncTCPClient {
  public:
  SyncTCPClient(const std::string &raw_ip_address, unsigned short port_num);

  void connect();

  void close();

  std::string emulateLongComputationOp(unsigned int duration_sec);

  private:
  void sendRequest(const std::string &request);

  std::string receiveResponse();

  private:
  boost::asio::io_context m_ios;

  boost::asio::ip::tcp::endpoint m_ep;
  boost::asio::ip::tcp::socket m_sock;
};
