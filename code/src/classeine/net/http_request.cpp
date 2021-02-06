#include "classeine/net/http_request.h"

#include "civetweb.h"

#include "classeine/core/string_tools.h"

using namespace classeine::core;

classeine::net::http_request::http_request(const mg_request_info &request)
    : request{request}, method{from_string(request.request_method)}
{
}

std::string_view
classeine::net::http_request::get_query_string() const noexcept
{
    return string_tools::to_safe_string_view(request.query_string);
}

std::string_view
classeine::net::http_request::get_uri() const noexcept
{
    return string_tools::to_safe_string_view(request.request_uri);
}

classeine::net::http_method
classeine::net::http_request::get_method() const noexcept
{
    return method;
}
