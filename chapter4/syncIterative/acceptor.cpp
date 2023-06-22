#include "acceptor.h"
#include "service.h"

Acceptor::Acceptor(boost::asio::io_context& ios, unsigned short port_num)
    : m_ios(ios),
      m_acceptor(m_ios, boost::asio::ip::tcp::endpoint(
                            boost::asio::ip::address_v4::any(), port_num)) {
  m_acceptor.listen();
}

void Acceptor::Accept() {
  boost::asio::ip::tcp::socket sock(m_ios);

  m_acceptor.accept(sock);

  Service svc;
  svc.HandleClient(sock);
}
