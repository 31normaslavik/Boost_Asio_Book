#include "server.h"
#include "acceptor.h"

Server::Server() : m_stop(false) {}

void Server::start(unsigned short port_num) {
  m_thread =
      std::make_unique<std::thread>([this, port_num]() { run(port_num); });
}

void Server::stop() {
  m_stop.store(true);
  m_thread->join();
}

void Server::run(unsigned short port_num) {
  Acceptor acc(m_ios, port_num);

  while (!m_stop.load()) {
    acc.accept();
  }
}
