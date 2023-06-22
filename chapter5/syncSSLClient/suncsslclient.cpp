#include "suncsslclient.h"
#include <boost/asio/read_until.hpp>
#include <boost/asio/streambuf.hpp>

SyncSSLClient::SyncSSLClient(const std::string &raw_ip_address, unsigned short port_num)
    : m_ep(boost::asio::ip::address::from_string(raw_ip_address), port_num)
    , m_ssl_context(boost::asio::ssl::context::sslv23)
    , m_ssl_stream(m_ios, m_ssl_context)
{
    // Set verification mode and designate that
    // we want to perform verification.
    m_ssl_stream.set_verify_mode(boost::asio::ssl::verify_peer);

    // Set verification callback.
    m_ssl_stream.set_verify_callback(
        [this](bool preverified, boost::asio::ssl::verify_context &context) -> bool {
            return on_peer_verify(preverified, context);
        });
}

void SyncSSLClient::connect()
{
    // Connect the TCP socket.
    m_ssl_stream.lowest_layer().connect(m_ep);

    // Perform the SSL handshake.
    m_ssl_stream.handshake(boost::asio::ssl::stream_base::client);
}

void SyncSSLClient::close()
{
    // We ignore any errors that might occur
    // during shutdown as we anyway can't
    // do anything about them.
    boost::system::error_code ec;

    m_ssl_stream.shutdown(ec); // Shutown SSL.

    // Shut down the socket.
    m_ssl_stream.lowest_layer().shutdown(boost::asio::ip::tcp::socket::shutdown_both, ec);

    m_ssl_stream.lowest_layer().close(ec);
}

std::string SyncSSLClient::emulate_long_computation_op(unsigned int duration_sec)
{
    std::string request = "EMULATE_LONG_COMP_OP " + std::to_string(duration_sec) + "\n";

    send_request(request);
    return receive_response();
}

bool SyncSSLClient::on_peer_verify(bool preverified, boost::asio::ssl::verify_context &context)
{
    // Here the certificate should be verified and the
    // verification result should be returned.
    return true;
}

void SyncSSLClient::send_request(const std::string &request)
{
    boost::asio::write(m_ssl_stream, boost::asio::buffer(request));
}

std::string SyncSSLClient::receive_response()
{
    boost::asio::streambuf buf;
    boost::asio::read_until(m_ssl_stream, buf, '\n');

    std::string response;
    std::istream input(&buf);
    std::getline(input, response);

    return response;
}
