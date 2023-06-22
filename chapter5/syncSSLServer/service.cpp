#include "service.h"

void Service::handle_client(
    boost::asio::ssl::stream<boost::asio::ip::tcp::socket>& ssl_stream) {
  try {
    // Blocks until the handshake completes.
    ssl_stream.handshake(boost::asio::ssl::stream_base::server);

    boost::asio::streambuf request;
    boost::asio::read_until(ssl_stream, request, '\n');

    // Emulate request processing.
    int i = 0;
    while (i != 1000000)
      i++;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    // Sending response.
    std::string response = "Response\n";
    boost::asio::write(ssl_stream, boost::asio::buffer(response));
  } catch (boost::system::system_error& e) {
    std::cerr << "Error occured! Error code = " << e.code()
              << ". Message: " << e.what();
  }
}
