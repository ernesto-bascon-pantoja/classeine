#pragma once

#include <iostream>
#include <sstream>
#include <string_view>
#include <vector>


namespace classeine::core::string_tools
{
    constexpr std::string_view empty_string = "";

    void hello_world();

    bool starts_with(const std::string& str, const std::string& prefix);

    std::string_view to_safe_string_view(const char* str);

    template <typename T>
    void build_stream(std::ostream& os, const T& val)
    {
        os << val;
    }

    template <typename T, typename... Args>
    void build_stream(std::ostream& os, const T& val, const Args&... args)
    {
        os << val;

        build_stream(os, args...);
    }

    template <typename... Args>
    std::string build_string(const Args&... args)
    {
        std::stringstream ss;
        build_stream(ss, args...);
        return ss.str();
    }

    template <typename ... Args>
    inline void println(const Args&... values)
    {
        build_stream(std::cout, values..., '\n');
    }

    std::vector<std::string_view> split(const std::string_view& str, char delimiter);

    template <typename T>
    void println_iterable(const T& iterable)
    {
        auto index = 0U;
        for (auto& e : iterable)
        {
            println(index++, ' ', e);
        }
    }
}