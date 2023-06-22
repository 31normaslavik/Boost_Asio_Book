#include "server.h"
#include "acceptor.h"
#include <thread>

Server::Server() : m_stop(false) {}

void Server::Start(unsigned short port_num) {
  m_thread.reset(new std::thread([this, port_num]() { Run(port_num); }));
}

void Server::Stop() {
  m_stop.store(true);
  m_thread->join();
}

void Server::Run(unsigned short port_num) {
  Acceptor acc(m_ios, port_num);

  while (!m_stop.load()) {
    acc.Accept();
  }
}
