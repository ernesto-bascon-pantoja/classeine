#pragma once

namespace classeine::core
{
    /**
     * This class deletes copy and move constructor and operator=, rendering this object
     * unable to be copied or moved.
     */
    class unique_object
    {
    protected:
        unique_object() = default;

    public:
        unique_object(const unique_object& ) = delete;
        unique_object(unique_object&& ) = delete;

        auto& operator=(const unique_object& ) = delete;
        auto& operator=(unique_object&& ) = delete;
    };
}