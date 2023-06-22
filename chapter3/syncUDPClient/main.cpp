#include "syncudpclient.h"

#include <iostream>

#include <boost/system/system_error.hpp>

int main()
{
	const std::string server1_raw_ip_address = "127.0.0.1";
	const unsigned short server1_port_num = 3333;

	const std::string server2_raw_ip_address = "192.168.1.10";
	const unsigned short server2_port_num = 3334;

	try {
		SyncUDPClient client;

		std::cout << "Sending request to the server #1 ... "
			<< std::endl;

		std::string response =
			client.emulateLongComputationOp(10,
			server1_raw_ip_address, server1_port_num);

		std::cout << "Response from the serever #1 received: "
			<< response << std::endl;

		std::cout << "Sending request to the server #2... "
			<< std::endl;

		response =
			client.emulateLongComputationOp(10,
			server2_raw_ip_address, server2_port_num);

		std::cout << "Response from the server #2 received: "
			<< response << std::endl;
        } catch (boost::system::system_error &e) {
                std::cout << "Error occured! Error code = " << e.code()
			<< ". Message: " << e.what();

		return e.code().value();
        }

        return 0;
}
