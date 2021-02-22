#pragma once

#include "classeine/core/exception.h"

#include "http_status_codes.h"

namespace classeine::net
{
    class http_exception : public classeine::core::exception
    {
        http_status_codes code;

    public:
        template <typename String>
        http_exception(http_status_codes code, String&& extended_message)
            : exception(to_string(code), extended_message)
        {
        }

        http_status_codes get_status_code() const noexcept;
    };
}