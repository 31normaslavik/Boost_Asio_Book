
#include "asynctcpclient.h"

#include <iostream>

int main(int argc, char **argv)
{
    try
    {
        AsyncTCPClient client;

        // Here we emulate the user�s behavior.

        // User initiates a request with id 1.
        client.emulateLongComputationOp(10, "127.0.0.1", 3333, handler, 1);

        // Then does nothing for 5 seconds.
        std::this_thread::sleep_for(std::chrono::seconds(5));

        // Then initiates another request with id 2.
        client.emulateLongComputationOp(11, "127.0.0.1", 3334, handler, 2);

        // Then decides to cancel the request with id 1.
        client.cancelRequest(1);

        // Does nothing for another 6 seconds.
        std::this_thread::sleep_for(std::chrono::seconds(6));

        // Initiates one more request assigning ID 3 to it.
        client.emulateLongComputationOp(12, "127.0.0.1", 3335, handler, 3);

        // Does nothing for another 15 seconds.
        std::this_thread::sleep_for(std::chrono::seconds(15));

        // Decides to exit the application.
        client.close();
    } catch (boost::system::system_error &e) {
        std::cout << "Error occured! Error code = " << e.code()
                  << ". Message: " << e.what();

        return e.code().value();
    }

    return 0;
};
