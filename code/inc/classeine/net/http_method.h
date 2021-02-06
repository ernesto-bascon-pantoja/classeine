#pragma once

#include <string_view>

namespace classeine::net
{
    enum class http_method
    {
        get,
        head,
        post,
        put,
        del,
        trace,
        options,
        connect,
        unknown
    };

    http_method from_string(const std::string_view& str);

    std::string_view to_string(http_method method);
}