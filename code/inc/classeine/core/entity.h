#pragma once

#include "classeine/core/log_writer.h"

namespace classeine::core
{
    template <typename Domain>
    class entity : public unique_object
    {
        Domain& domain;
        std::string name;
        log_writer<typename Domain::logger_type> the_log_writer;

    protected:
        entity(Domain& domain, const std::string& name)
            : domain{domain},
              name{name},
              the_log_writer{domain.create_log_writer(name, true)}
        {

        }

        auto& get_conf() noexcept { return domain.get_conf(); }
        const auto& get_conf() const noexcept { return domain.get_conf(); }

        template <typename...Args>
        void log_error(const Args&... args)
        {
            the_log_writer.log_error(args...);
        }

        template <typename...Args>
        void log_warning(const Args&... args)
        {
            the_log_writer.log_warning(args...);
        }

        template <typename...Args>
        void log_info(const Args&... args)
        {
            the_log_writer.log_info(args...);
        }

        template <typename...Args>
        void log_debug(const Args&... args)
        {
            the_log_writer.log_debug(args...);
        }
    };
}