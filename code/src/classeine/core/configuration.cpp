#include "classeine/core/configuration.h"

std::shared_ptr<classeine::core::configuration>
classeine::core::make_configuration()
{
    return std::make_shared<configuration>();
}

void classeine::core::configuration::set(const std::string &section, const std::string &key, const std::string &value)
{
    sections[section][key] = value;
}

const std::string&
classeine::core::configuration::get_or_default(const std::string &section_name, const std::string &key,
                                               const std::string &default_value) const
{
    auto section_it = sections.find(section_name);
    if (section_it == sections.end())
        return default_value;

    auto& section = section_it->second;

    auto value_it = section.find(key);
    if (value_it == section.end())
        return default_value;

    return value_it->second;
}