#pragma once

#include "function.h"
#include "session.h"
#include <boost/asio/detail/noncopyable.hpp>

#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <map>
#include <memory>
#include <string>
#include <thread>

class AsyncTCPClient : public boost::asio::noncopyable {
  public:
  AsyncTCPClient();

  void emulateLongComputationOp(unsigned int duration_sec,
                                const std::string &raw_ip_address,
                                unsigned short port_num, Callback callback,
                                unsigned int request_id);

  // Cancels the request.
  void cancelRequest(unsigned int request_id);

  void close() {
    // Destroy work object. This allows the I/O thread to
    // exits the event loop when there are no more pending
    // asynchronous operations.
    m_work.reset();

    // Wait for the I/O thread to exit.
    m_thread->join();
  }

  private:
  void onRequestComplete(std::shared_ptr<Session> session);

  private:
  boost::asio::io_context m_ios;
  std::map<int, std::shared_ptr<Session>> m_active_sessions;
  std::mutex m_active_sessions_guard;
  boost::asio::executor_work_guard<boost::asio::io_context::executor_type>
      m_work;
  std::unique_ptr<std::thread> m_thread;
};
