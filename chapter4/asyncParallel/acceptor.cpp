#include "acceptor.h"
#include "service.h"
#include <iostream>

Acceptor::Acceptor(boost::asio::io_context& ios, unsigned short port_num)
    : m_ios(ios),
      m_acceptor(m_ios, boost::asio::ip::tcp::endpoint(
                            boost::asio::ip::address_v4::any(), port_num)),
      m_isStopped(false) {}

void Acceptor::Start() {
  m_acceptor.listen();
  InitAccept();
}

void Acceptor::Stop() { m_isStopped.store(true); }

void Acceptor::InitAccept() {
  std::shared_ptr<boost::asio::ip::tcp::socket> sock(
      new boost::asio::ip::tcp::socket(m_ios));

  m_acceptor.async_accept(*sock.get(),
                          [this, sock](const boost::system::error_code& error) {
                            onAccept(error, sock);
                          });
}

void Acceptor::onAccept(const boost::system::error_code& ec,
                        std::shared_ptr<boost::asio::ip::tcp::socket> sock) {
  if (ec.value() == 0) {
    (new Service(sock))->StartHandling();
  } else {
    std::cout << "Error occured! Error code = " << ec.value()
              << ". Message: " << ec.message();
  }

  // Init next async accept operation if
  // acceptor has not been stopped yet.
  if (!m_isStopped.load()) {
    InitAccept();
  } else {
    // Stop accepting incoming connections
    // and free allocated resources.
    m_acceptor.close();
  }
}
