#include "classeine/core/exception.h"


const char*
classeine::core::exception::what() const noexcept
{
    return message.c_str();
}

const std::string&
classeine::core::exception::get_message() const noexcept
{
    return message;
}

const std::string&
classeine::core::exception::get_extended_message() const noexcept
{
    return extended_message;
}