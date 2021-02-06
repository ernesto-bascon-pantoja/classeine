#pragma once

#include <string_view>

#include "http_method.h"

struct mg_request_info;

namespace classeine::net
{
    class http_request
    {
        const mg_request_info& request;
        http_method method;

    public:
        http_request(const mg_request_info& request);

        std::string_view get_query_string() const noexcept;
        std::string_view get_uri() const noexcept;

        http_method get_method() const noexcept;
    };
}