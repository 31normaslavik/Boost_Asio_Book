#pragma once

#include "service.h"

#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>

class Acceptor {
  public:
  Acceptor(boost::asio::io_context &ios, unsigned short port_num);

  void Accept() {
    std::shared_ptr<boost::asio::ip::tcp::socket> sock =
        std::make_shared<boost::asio::ip::tcp::socket>(m_ios);

    m_acceptor.accept(*sock.get());

    (new Service)->StartHandligClient(sock);
  }

  private:
  boost::asio::io_context &m_ios;
  boost::asio::ip::tcp::acceptor m_acceptor;
};
