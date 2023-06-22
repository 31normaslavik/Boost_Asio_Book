#pragma once

#include "acceptor.h"
#include <assert.h>

class Server
{
public:
    Server();

    // Start the server.
    void Start(unsigned short port_num, unsigned int thread_pool_size);

    // Stop the server.
    void Stop();

private:
    boost::asio::io_context m_ios;
    boost::asio::executor_work_guard<boost::asio::io_context::executor_type> m_work;
    std::unique_ptr<Acceptor> acc;
    std::vector<std::unique_ptr<std::thread>> m_thread_pool;
};
