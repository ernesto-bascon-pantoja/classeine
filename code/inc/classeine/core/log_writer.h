#pragma onceonce

#include "log_level.h"
#include "string_tools.h"

namespace classeine::core
{
    template <typename Logger>
    class log_writer
    {
        Logger& logger;
        std::string context;
        bool start_end_output;

    public:
        template <typename String>
        log_writer(Logger& logger, String&& context, bool start_end_output) :
            logger{logger},
            context{std::forward<const std::string>(context)},
            start_end_output{start_end_output}
        {
            if (start_end_output)
                debug("Starting [", context, "]");
        }

        log_writer(const log_writer<Logger>& ) = delete;
        log_writer(log_writer<Logger>&& ) = delete;

        auto& operator=(const log_writer<Logger>& ) = delete;
        auto& operator=(log_writer<Logger>& ) = delete;

        auto create_logger(const std::string& subcontext, bool start_end_output)
        {
            std::string context_name = string_tools::build_string(context, " | ", subcontext);
            return logger.create_logger(context_name, start_end_output);
        }

        ~log_writer()
        {
            if (start_end_output)
                debug("Finishing [", context, "]");
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

            logger.get_output().write(level, context, string_tools::build_string(args...));
        }
    };
}