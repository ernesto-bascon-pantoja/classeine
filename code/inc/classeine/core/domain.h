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

        template <typename...Args>
        void error(const Args&... args)
        {
            the_log_writer.error(log_level::error, args...);
        }

        template <typename...Args>
        void warning(const Args&... args)
        {
            the_log_writer.warning(log_level::warning, args...);
        }

        template <typename...Args>
        void info(const Args&... args)
        {
            the_log_writer.info(log_level::info, args...);
        }

        template <typename...Args>
        void debug(const Args&... args)
        {
            the_log_writer.debug(log_level::debug, args...);
        }
    };
}