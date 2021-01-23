#pragma once

#include "classeine/core/entity.h"

namespace classeine::net
{
    using namespace classeine::core;

    template <typename Logger>
    class rest_server : public entity<Logger>
    {
    public:
        rest_server(domain<Logger>& parent_domain)
            : entity<Logger>{parent_domain, "rest_server", true}
        {

        }

    };
}