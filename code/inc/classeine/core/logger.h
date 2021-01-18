#pragma once

#include "_concept_log_output.h"
#include "configuration.h"
#include "log_level.h"
#include "log_writer.h"

namespace classeine::core
{
    template <CLogOutput Output>
    class logger
    {
        const configuration& conf;
        log_level output_level;
        Output output;

    public:
        logger(const configuration& conf)
            : conf{conf},
              output_level{static_cast<log_level>(std::stoi(conf.get_or_default("log", "level", "3")))}
        {
        }

        logger(const logger<Output>& ) = delete;
        logger(logger<Output>&& ) = delete;

        auto& operator=(const logger<Output>& ) = delete;
        auto& operator=(logger<Output>&& ) = delete;

        log_writer<logger<Output>> create_logger(const std::string& context_name, bool start_end_output)
        {
            return log_writer<logger<Output>>{*this, context_name, start_end_output};
        }

        Output& get_output() noexcept
        {
            return output;
        }

        const Output& get_output() const noexcept
        {
            return output;
        }

        log_level get_output_level() const noexcept
        {
            return output_level;
        }
    };
}