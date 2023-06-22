#pragma once
#include <boost/asio/io_context.hpp>

#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/context.hpp>

class Acceptor {
  public:
  Acceptor(boost::asio::io_context &ios, unsigned short port_num);

  void accept();

  private:
  std::string
  get_password(std::size_t max_length,
               boost::asio::ssl::context::password_purpose purpose) const;

  private:
  boost::asio::io_context &m_ios;
  boost::asio::ip::tcp::acceptor m_acceptor;

  boost::asio::ssl::context m_ssl_context;
};
