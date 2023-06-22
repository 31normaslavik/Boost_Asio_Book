#pragma once

#include <memory>
#include <thread>

#include <boost/asio/io_context.hpp>
class Server {
  public:
  Server();

  void Start(unsigned short port_num);

  void Stop();

  private:
  void Run(unsigned short port_num);

  std::unique_ptr<std::thread> m_thread;
  std::atomic<bool> m_stop;
  boost::asio::io_context m_ios;
};
