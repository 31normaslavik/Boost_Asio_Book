#pragma once

#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>

class Acceptor {
  public:
  Acceptor(boost::asio::io_context &ios, unsigned short port_num);

  void Accept();

  private:
  boost::asio::io_context &m_ios;
  boost::asio::ip::tcp::acceptor m_acceptor;
};
