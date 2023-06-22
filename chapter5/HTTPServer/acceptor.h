#pragma once

#include <boost/asio.hpp>
#include <iostream>

class Acceptor
{
public:
    Acceptor(boost::asio::io_context &ios, unsigned short port_num);

    // Start accepting incoming connection requests.
    void Start();

    // Stop accepting incoming connection requests.
    void Stop();

private:
    void InitAccept();

    void onAccept(const boost::system::error_code &ec,
                  std::shared_ptr<boost::asio::ip::tcp::socket> sock);

private:
    boost::asio::io_context &m_ios;
    boost::asio::ip::tcp::acceptor m_acceptor;
    std::atomic<bool> m_isStopped;
};
