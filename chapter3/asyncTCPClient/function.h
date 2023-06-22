#pragma once

#include <boost/system/error_code.hpp>

// Function pointer type that points to the callback
// function which is called when a request is complete.
// typedef void (*Callback)(unsigned int request_id, const std::string
// &response,
//                         const boost::system::error_code &ec);

typedef std::function<void(unsigned int request_id, const std::string &response,
                           const boost::system::error_code &ec)>
    Callback;

void handler(unsigned int request_id, const std::string &response,
             const boost::system::error_code &ec);
