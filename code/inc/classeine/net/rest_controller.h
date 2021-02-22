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
        using rest_endpoint_type = rest_endpoint<ParentEntity>;

        std::vector<rest_endpoint<rest_endpoint_type>> endpoints;

        ParentEntity& parent;
        std::string name;

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

        std::optional<std::reference_wrapper<rest_endpoint_type>> get_matching_endpoint(const rest_path& path)
        {
            return { };
        }

        const std::string& get_name() const noexcept { return name; }
    };

    template <typename Controller, typename Domain>
    static std::unique_ptr<Controller> create_controller(Domain& parent)
    {
        return std::make_unique<Controller>(parent);
    }
}