#include "classeine/net/rest_path.h"

#include "classeine/core/string_tools.h"


classeine::net::rest_path::rest_path(const classeine::net::http_request& request)
    : path { classeine::core::string_tools::split(request.get_uri(), '/')}
{
}

std::string_view
classeine::net::rest_path::get_controller_name() const noexcept
{
    if (path.size() < 2)
        return classeine::core::string_tools::empty_string;

    return path[1];
}