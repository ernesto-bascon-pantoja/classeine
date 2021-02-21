#pragma once

#include "configuration.h"
#include "log_writer.h"
#include "unique_object.h"

namespace classeine::core
{
    template <typename Logger>
    class domain : public unique_object
    {
    public:
        using logger_type = Logger;

    private:
        const configuration& conf;
        Logger logger;
        std::string name;
        log_writer<Logger> the_log_writer;

    protected:
        domain(const configuration& conf, const std::string& name)
            : conf{conf},
              logger{conf},
              name{name},
              the_log_writer{logger.create_writer(name, true)}
        {
        }

    public:
        ~domain()
        {
        }

        auto create_log_writer(const std::string& context_name, bool log_start_and_end)
        {
            return the_log_writer.create_writer(context_name, log_start_and_end);
        }

        auto& get_conf() noexcept { return conf; }
        const auto& get_conf() const noexcept { return conf;}


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