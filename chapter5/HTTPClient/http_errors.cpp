#include "http_errors.h"

std::string http_errors::http_errors_category::message(int e) const {
  switch (e) {
  case invalid_response:
    return "Server response cannot be parsed.";
    break;
  default:
    return "Unknown error.";
    break;
  }
}

const boost::system::error_category& http_errors::get_http_errors_category() {
  static http_errors_category cat;
  return cat;
}

boost::system::error_code http_errors::make_error_code(http_error_codes e) {
  return boost::system::error_code(static_cast<int>(e),
                                   get_http_errors_category());
}
