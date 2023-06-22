#include <boost/asio.hpp>
//#include <boost/filesystem.hpp>

#include "server.h"
#include "service.h"
#include <atomic>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <thread>
using namespace boost;


const std::map<unsigned int, std::string> Service::http_status_table
    = {{200, "200 OK"},
       {404, "404 Not Found"},
       {413, "413 Request Entity Too Large"},
       {500, "500 Server Error"},
       {501, "501 Not Implemented"},
       {505, "505 HTTP Version Not Supported"}};



const unsigned int DEFAULT_THREAD_POOL_SIZE = 2;

int main()
{
    unsigned short port_num = 3333;

    try {
        Server srv;

        unsigned int thread_pool_size = std::thread::hardware_concurrency() * 2;

        if (thread_pool_size == 0)
            thread_pool_size = DEFAULT_THREAD_POOL_SIZE;

        srv.Start(port_num, thread_pool_size);

        std::this_thread::sleep_for(std::chrono::seconds(60));

        srv.Stop();
    } catch (system::system_error &e) {
        std::cout << "Error occured! Error code = " << e.code() << ". Message: " << e.what();
    }

    return 0;
}
