#pragma once

#include <vector>
#include <string_view>

#include "http_request.h"

namespace classeine::net
{
    class rest_path
    {
        std::vector<std::string_view> path;

    public:
        rest_path(const http_request& req);

        std::string_view get_controller_name() const noexcept;

    };
}