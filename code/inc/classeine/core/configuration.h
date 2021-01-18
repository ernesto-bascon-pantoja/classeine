#pragma once

#include <unordered_map>
#include <string>

namespace classeine::core
{
    class configuration
    {
    private:
        std::unordered_map<std::string, std::unordered_map<std::string, std::string>> sections;

    public:
        configuration() = default;

        configuration(const configuration& ) = delete;
        configuration(configuration&& ) = delete;

        auto& operator=(const configuration& ) = delete;
        auto& operator=(configuration&& ) = delete;

        void set(const std::string& section, const std::string& key, const std::string& value);

        const std::string& get_or_default(
                        const std::string& section,
                        const std::string& key,
                        const std::string& default_value) const;
    };
}