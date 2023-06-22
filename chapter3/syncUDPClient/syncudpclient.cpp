#include "syncudpclient.h"

SyncUDPClient::SyncUDPClient() : m_sock(m_ios) {
  m_sock.open(boost::asio::ip::udp::v4());
}

std::string
SyncUDPClient::emulateLongComputationOp(unsigned int duration_sec,
                                        const std::string& raw_ip_address,
                                        unsigned short port_num) {

  std::string request =
      "EMULATE_LONG_COMP_OP " + std::to_string(duration_sec) + "\n";

  boost::asio::ip::udp::endpoint ep(
      boost::asio::ip::address::from_string(raw_ip_address), port_num);

  sendRequest(ep, request);
  return receiveResponse(ep);
}

void SyncUDPClient::sendRequest(const boost::asio::ip::udp::endpoint& ep,
                                const std::string& request) {

  m_sock.send_to(boost::asio::buffer(request), ep);
}

std::string SyncUDPClient::receiveResponse(boost::asio::ip::udp::endpoint& ep) {
  char response[6];
  std::size_t bytes_recieved =
      m_sock.receive_from(boost::asio::buffer(response), ep);

  m_sock.shutdown(boost::asio::ip::udp::socket::shutdown_both);
  return std::string(response, bytes_recieved);
}
