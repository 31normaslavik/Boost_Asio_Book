#pragma once

#include "function.h"
#include <boost/asio/io_context.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/streambuf.hpp>

// Structure represents a context of a single request.
struct Session {
  Session(boost::asio::io_context &ios, const std::string &raw_ip_address,
          unsigned short port_num, const std::string &request, unsigned int id,
          Callback callback);

  boost::asio::ip::tcp::socket m_sock; // Socket used for communication
  boost::asio::ip::tcp::endpoint m_ep; // Remote endpoint.
  std::string m_request; // Request string.

  // streambuf where the response will be stored.
  boost::asio::streambuf m_response_buf;
  std::string m_response; // Response represented as a string.

  // Contains the description of an error if one occurs during
  // the request lifecycle.
  boost::system::error_code m_ec;

  unsigned int m_id; // Unique ID assigned to the request.

  // Pointer to the function to be called when the request
  // completes.
  Callback m_callback;

  bool m_was_cancelled;
  std::mutex m_cancel_guard;
};
