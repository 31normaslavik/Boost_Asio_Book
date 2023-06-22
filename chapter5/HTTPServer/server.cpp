#include "server.h"

Server::Server()
    : m_work{boost::asio::make_work_guard(m_ios)}
{}

void Server::Start(unsigned short port_num, unsigned int thread_pool_size)
{
    assert(thread_pool_size > 0);

    // Create and strat Acceptor.
    acc = std::make_unique<Acceptor>(m_ios, port_num);
    acc->Start();

    // Create specified number of threads and
    // add them to the pool.
    for (unsigned int i = 0; i < thread_pool_size; i++) {
        std::unique_ptr<std::thread> th(new std::thread([this]() { m_ios.run(); }));

        m_thread_pool.push_back(std::move(th));
    }
}

void Server::Stop()
{
    acc->Stop();
    m_ios.stop();

    for (auto &th : m_thread_pool) {
        th->join();
    }
}
