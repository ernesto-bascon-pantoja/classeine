#pragma once

#include "classeine/core/entity.h"

namespace classeine::net
{
    using namespace classeine::core;

    template <typename Domain>
    class rest_server : public entity<Domain>
    {
    public:
        rest_server(Domain& parent_domain)
            : entity<Domain>{parent_domain, "rest_server"}
        {
        }
    };
}