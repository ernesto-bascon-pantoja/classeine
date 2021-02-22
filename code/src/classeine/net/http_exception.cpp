#include "classeine/net/http_exception.h"

classeine::net::http_status_codes
classeine::net::http_exception::get_status_code() const noexcept
{
    return code;
}