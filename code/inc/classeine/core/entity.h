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
        void error(const Args&... args)
        {
            the_log_writer.error(args...);
        }

        template <typename...Args>
        void warning(const Args&... args)
        {
            the_log_writer.warning(args...);
        }

        template <typename...Args>
        void info(const Args&... args)
        {
            the_log_writer.info(args...);
        }

        template <typename...Args>
        void debug(const Args&... args)
        {
            the_log_writer.debug(args...);
        }
    };
}