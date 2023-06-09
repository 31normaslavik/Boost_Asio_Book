
#include <boost/asio.hpp>
#include <iostream>
#include <thread>

using namespace boost;

int main() {
  std::string raw_ip_address = "127.0.0.1";
  unsigned short port_num = 3333;

  try {
    asio::ip::tcp::endpoint ep(asio::ip::address::from_string(raw_ip_address),
                               port_num);

    asio::io_context ios;

    std::shared_ptr<asio::ip::tcp::socket> sock(
        new asio::ip::tcp::socket(ios, ep.protocol()));

    sock->async_connect(ep, [sock](const boost::system::error_code &ec) {
      // If asynchronous operation has been
      // cancelled or an error occured during
      // executon, ec contains corresponding
      // error code.
      if (ec.value() != 0) {
        if (ec == asio::error::operation_aborted) {
          std::cout << "Operation cancelled!";
        } else {
          std::cout << "Error occured!"
                    << " Error code = " << ec.value()
                    << ". Message: " << ec.message();
        }

        return;
      }
      // At this point the socket is connected and
      // can be used for communication with
      // remote application.
    });

    // Starting a thread, which will be used
    // to call the callback when asynchronous
    // operation completes.
    std::thread worker_thread([&ios]() {
      try {
        ios.run();
      } catch (system::system_error &e) {
        std::cout << "Error occured!"
                  << " Error code = " << e.code() << ". Message: " << e.what();
      }
    });

    // Emulating delay.
    std::this_thread::sleep_for(std::chrono::seconds(5));

    // Cancelling the initiated operation.
    sock->cancel();

    // Waiting for the worker thread to complete.
    worker_thread.join();
  } catch (system::system_error &e) {
    std::cout << "Error occured! Error code = " << e.code()
              << ". Message: " << e.what();

    return e.code().value();
  }

  return 0;
}
