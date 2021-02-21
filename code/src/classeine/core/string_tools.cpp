#include "classeine/core/string_tools.h"


void classeine::core::string_tools::hello_world()
{
    println("Hello world from Classeine.");
}

bool classeine::core::string_tools::starts_with(const std::string& str, const std::string& prefix)
{
    std::string_view sv = str;
    return sv.starts_with(prefix);
}

std::string_view
classeine::core::string_tools::to_safe_string_view(const char *str)
{
    return str == nullptr ? "" : str;
}

std::vector<std::string_view>
classeine::core::string_tools::split(const std::string_view& s, char delimiter)
{
    std::vector<std::string_view> elements;

    auto it = s.begin();
    auto init_it = it;
    for ( ; it != s.end(); ++it)
    {
        if (*it == delimiter)
        {
            std::string_view aux { init_it, it };
            if (!aux.empty())
                elements.push_back(std::move(aux));

            init_it = it + 1;
        }
    }

    std::string_view aux { init_it, it };
    if (!aux.empty())
        elements.emplace_back(std::move(aux));

    return elements;
}