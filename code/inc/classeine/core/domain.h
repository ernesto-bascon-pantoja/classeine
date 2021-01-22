#pragma once

#include "configuration.h"

namespace classeine::core
{
    template <typename Logger>
    class domain : public unique_object
    {
        const configuration& conf;
        std::string name;
        Logger logger;

    public:
        domain(const configuration& conf,
               const std::string& name,
               bool start_end_output)
            : conf{conf}, name{name},
              logger{conf, name, start_end_output}
        {
        }

        auto& get_conf() noexcept { return conf; }
        const auto& get_conf() const noexcept { return conf; }

        const std::string& get_name() const noexcept { return name; }

        auto& get_logger() noexcept { return logger; }
        auto& get_logger() const noexcept { return logger; }
    };
}