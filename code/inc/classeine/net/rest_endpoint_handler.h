#pragma once

#include <string>
#include <unordered_map>

#include "http_request.h"
#include "http_response.h"

namespace classeine::net
{
    template <typename ParentEntity>
    using rest_endpoint_handler =
                http_response(*)(
                        ParentEntity&,
                        const http_request&,
                        const std::unordered_map<std::string, std::string>& params);
}