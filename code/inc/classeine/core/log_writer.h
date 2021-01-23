#pragma once

#include "configuration.h"
#include "log_level.h"
#include "string_tools.h"
#include "unique_object.h"

#include <memory>

namespace classeine::core
{
    template <typename Logger>
    class log_writer : public unique_object
    {
        const configuration& conf;
        Logger& logger;
        std::string context_name;
        bool start_end_output;

    public:
        template <typename String>
        log_writer(
                const configuration& conf,
                Logger& logger,
                String&& context_name,
                bool start_end_output)
            :
                conf{conf},
                logger{logger},
                context_name{std::forward<const std::string>(context_name)},
                start_end_output{start_end_output}
        {
            if (start_end_output)
                write(log_level::debug, "Started [", context_name, "]");
        }

    public:
        auto create_writer(const std::string& subcontext, bool start_end_output)
        {
            std::string context_name = string_tools::build_string(context_name, "::", subcontext);
            return log_writer<Logger>{conf, logger, std::move(context_name), start_end_output};
        }

        ~log_writer()
        {
            if (start_end_output)
                write(log_level::debug, "Finished [", context_name, "]");
        }

        template <typename...Args>
        void error(const Args&... args)
        {
            write(log_level::error, args...);
        }

        template <typename...Args>
        void warning(const Args&... args)
        {
            write(log_level::warning, args...);
        }

        template <typename...Args>
        void info(const Args&... args)
        {
            write(log_level::info, args...);
        }

        template <typename...Args>
        void debug(const Args&... args)
        {
            write(log_level::debug, args...);
        }

    private:
        template <typename... Args>
        void write(log_level level, const Args&... args)
        {
            if (static_cast<int>(level) > static_cast<int>(logger.get_output_level()))
                return;

            logger.get_output().write(level, context_name, string_tools::build_string(args...));
        }
    };
}