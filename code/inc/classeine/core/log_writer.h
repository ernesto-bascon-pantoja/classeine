#pragma onceonce

#include "configuration.h"
#include "log_level.h"
#include "string_tools.h"
#include "unique_object.h"

#include <memory>

namespace classeine::core
{
    template <typename Output>
    class log_writer : public unique_object
    {
        const configuration& conf;
        std::string context_name;
        bool start_end_output;

        std::shared_ptr<Output> output;

        log_level output_level;

    public:
        template <typename String>
        log_writer(const configuration& conf, String&& context_name, bool start_end_output) :
            log_writer{
                conf,
                context_name,
                start_end_output,
                std::make_shared<Output>(),
                static_cast<log_level>(std::stoi(conf.get_or_default("log", "level", "3")))}
        {

        }

    private:
        template <typename String>
        log_writer(
                const configuration& conf,
                String&& context_name,
                bool start_end_output,
                std::shared_ptr<Output> output,
                log_level output_level)
            :
                conf{conf},
                context_name{std::forward<const std::string>(context_name)},
                start_end_output{start_end_output},
                output{output},
                output_level{output_level}
        {
            if (start_end_output)
                write(log_level::debug, "Starting [", context_name, "]");
        }

    public:
        auto create_writer(const std::string& subcontext, bool start_end_output)
        {
            std::string context_name = string_tools::build_string(context_name, "::", subcontext);
            return log_writer<Output>{conf, context_name, start_end_output, output, output_level};
        }

        ~log_writer()
        {
            if (start_end_output)
                write(log_level::debug, "Finishing [", context_name, "]");
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
            if (static_cast<int>(level) > static_cast<int>(output_level))
                return;

            output->write(level, context_name, string_tools::build_string(args...));
        }
    };
}