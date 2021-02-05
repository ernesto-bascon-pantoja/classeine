#pragma once

#include "CLogOutput.h"

#include "log_writer.h"
#include "unique_object.h"


namespace classeine::core
{
    template <CLogOutput Output>
    class logger : public unique_object
    {
        Output output;
        log_level output_level;
        const configuration& conf;
        log_writer<logger<Output>> writer;

    public:
        logger(const configuration& conf)
            : conf{conf},
              output_level{static_cast<log_level>(std::stoi(conf.get_or_default("log", "level", "3")))},
              writer{create_writer("log", true)}
        {
            writer.log_debug("Log level: ", to_string(output_level));
        }

        auto create_writer(const std::string& context_name, bool start_end_log_output)
        {
            return log_writer<logger<Output>>{conf, *this, context_name, start_end_log_output};
        }

        log_level get_output_level() const noexcept { return output_level; }

        auto& get_output() noexcept { return output; }
        const auto& get_output() const noexcept { return output; }
    };
}