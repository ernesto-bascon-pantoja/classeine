#pragma once

#include "unique_object.h"

#include <memory>
#include <unordered_map>
#include <string>

namespace classeine::core
{
    class configuration final : public unique_object
    {
    private:
        std::unordered_map<std::string, std::unordered_map<std::string, std::string>> sections;

    public:
        void set(const std::string& section, const std::string& key, const std::string& value);

        const std::string& get_or_default(
                        const std::string& section,
                        const std::string& key,
                        const std::string& default_value) const;
    };

    std::shared_ptr<configuration> make_configuration();
}