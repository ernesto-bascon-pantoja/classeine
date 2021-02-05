#pragma once

#include <iostream>
#include <sstream>

namespace classeine::core::string_tools
{
    void hello_world();

    bool starts_with(const std::string& str, const std::string& prefix);

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

    template <typename T>
    inline void println(const T& value)
    {
        build_stream(std::cout, value, '\n');
    }
}