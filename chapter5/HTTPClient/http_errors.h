#pragma once

#include <boost/system/detail/error_category.hpp>
#include <boost/system/detail/error_code.hpp>

namespace http_errors {
enum http_error_codes { invalid_response = 1 };

class http_errors_category : public boost::system::error_category {
  public:
  const char *name() const noexcept { return "http_errors"; }

  std::string message(int e) const;
};

const boost::system::error_category &get_http_errors_category();

boost::system::error_code make_error_code(http_error_codes e);
} // namespace http_errors

namespace boost {
namespace system {
template<>
struct is_error_code_enum<http_errors::http_error_codes>
{
    BOOST_STATIC_CONSTANT(bool, value = true);
};

} // namespace system
} // namespace boost
