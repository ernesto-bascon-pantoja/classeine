#pragma once

#include <stdexcept>

namespace classeine::core
{
    class exception : public std::exception
    {
        std::string message;
        std::string extended_message;

    public:
        template <typename String1, typename String2>
        exception(String1&& message, String2&& extended_message)
        {
            this->message = std::forward<String1>(message);
            this->extended_message = std::forward<String2>(extended_message);
        }

        [[nodiscard]] const char* what() const noexcept final;

        [[nodiscard]] const std::string& get_message() const noexcept;
        [[nodiscard]] const std::string& get_extended_message() const noexcept;

        template <typename String>
        void set_message(String&& message)
        {
            this->message = std::forward<String>(message);
        }

        template <typename String>
        void set_extended_message(String&& message)
        {
            this->extended_message = std::forward<String>(extended_message);
        }
    };
}