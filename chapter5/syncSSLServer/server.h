#pragma once

#include <boost/asio/io_context.hpp>
#include <thread>

class Server {
  public:
  Server();

  void start(unsigned short port_num);

  void stop();

  private:
  void run(unsigned short port_num);

  std::unique_ptr<std::thread> m_thread;
  std::atomic<bool> m_stop;
  boost::asio::io_context m_ios;
};
