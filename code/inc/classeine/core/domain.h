#pragma once

#include "configuration.h"
#include "log_writer.h"

namespace classeine::core
{
    template <typename Logger>
    class domain : public unique_object
    {
        const configuration& conf;
        Logger logger;
        std::string name;
        log_writer<Logger> writer;

    public:
        domain(const configuration& conf, const std::string& name)
            : conf{conf},
              logger{conf},
              name{name},
              writer{logger.create_writer(name, true)}
        {
        }

        auto& get_conf() noexcept { return conf; }
        const auto& get_conf() const noexcept { return conf; }

        const std::string& get_name() const noexcept { return name; }

        auto& get_logger() noexcept { return logger; }
        auto& get_logger() const noexcept { return logger; }
    };
}