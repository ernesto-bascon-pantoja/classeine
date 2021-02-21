#pragma once

#include <string>
#include <unordered_map>

#include "rest_endpoint_handler.h"

namespace classeine::net
{
    template <typename ParentEntity>
    class rest_endpoint
    {
        http_method method;
        std::string path;
        rest_endpoint_handler<ParentEntity> handler;

    public:
        rest_endpoint(http_method method, const std::string& path, rest_endpoint_handler<ParentEntity> handler)
                : method{method},
                  path{path},
                  handler{handler}
        {
        }

        auto get_method() const noexcept { return method; }
        auto& get_path() const noexcept { return path; }

        http_response run(
                        ParentEntity& parent,
                        const http_request& request,
                        const std::unordered_map<std::string, std::string>& params)
        {
            return handler(parent, request, params);
        }
    };
}