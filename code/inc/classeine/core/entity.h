#pragma once

#include "configuration.h"
#include "domain.h"
#include "log_writer.h"

namespace classeine::core
{
    template <typename Logger>
    class entity : public unique_object
    {
        domain<Logger>& parent_domain;
        log_writer<Logger> writer;

    protected:
        entity(domain<Logger>& parent_domain, const std::string& context_name, bool start_end_log_output)
            : parent_domain{parent_domain}, writer{parent_domain.get_logger().create_writer(context_name, start_end_log_output)}
        {
        }

    public:
        template <typename...Args>
        void error(const Args&... args)
        {
            writer.write(log_level::error, args...);
        }

        template <typename...Args>
        void warning(const Args&... args)
        {
            writer.write(log_level::warning, args...);
        }

        template <typename...Args>
        void info(const Args&... args)
        {
            writer.write(log_level::info, args...);
        }

        template <typename...Args>
        void debug(const Args&... args)
        {
            writer.write(log_level::debug, args...);
        }

    };
}