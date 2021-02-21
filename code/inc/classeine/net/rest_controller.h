#pragma once

#include <vector>

#include "classeine/core/entity.h"

#include "classeine/net/rest_endpoint.h"
#include "rest_path.h"

namespace classeine::net
{
    template <typename ParentEntity>
    class rest_controller
    {
        std::vector<rest_endpoint<ParentEntity>> endpoints;

        ParentEntity& parent;
        std::string name;

        mutable rest_path cached_path;

    public:
        rest_controller(ParentEntity& parent, const std::string& name)
                    : parent{parent}, name{name}
        {
            parent.log_debug("Creating controller: [", name, "]");
        }

        ~rest_controller()
        {
            parent.log_debug("Deleting controller [", name, "]");
        }

        template <typename EndPoint>
        void add_endpoint(EndPoint&& endpoint)
        {
            endpoints.push_back(std::forward<EndPoint>(endpoint));
        }

        const std::string& get_name() const noexcept { return name; }
    };

    template <typename Controller, typename Domain>
    static std::unique_ptr<Controller> create_controller(Domain& parent)
    {
        return std::make_unique<Controller>(parent);
    }
}