#include "httpclient.h"

#include <boost/system/system_error.hpp>

#include <iostream>

int main()
{
    try {
        HTTPClient client;

        std::shared_ptr<HTTPRequest> request_one = client.create_request(1);

        request_one->set_host("localhost");
        request_one->set_uri("/index.html");
        request_one->set_port(3333);
        request_one->set_callback(handler);

        request_one->execute();

        std::this_thread::sleep_for(std::chrono::seconds(3));

        std::shared_ptr<HTTPRequest> request_two = client.create_request(1);

        request_two->set_host("localhost");
        request_two->set_uri("/example.html");
        request_two->set_port(3333);
        request_two->set_callback(handler);

        request_two->execute();

        request_two->cancel();

        // Do nothing for 15 seconds, letting the
        // request complete.
        std::this_thread::sleep_for(std::chrono::seconds(15));

        // Closing the client and exiting the application.
        client.close();
    } catch (const boost::system::system_error &e) {
        std::cout << "Error occured! Error code = " << e.code() << ". Message: " << e.what();

        return e.code().value();
    }

    return 0;
};
