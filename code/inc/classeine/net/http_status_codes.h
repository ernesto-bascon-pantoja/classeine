#pragma once

#include <string_view>

namespace classeine::net
{
    namespace http_status_code_names
    {
        constexpr std::string_view http_100_continue_str = "100 CONTINUE";
        constexpr std::string_view http_200_ok_str = "200 OK";
        constexpr std::string_view http_204_no_content_str = "204 NO CONTENT";
        constexpr std::string_view http_205_reset_content_str = "205 RESET CONTENT";
        constexpr std::string_view http_207_multistatus_str = "207 MULTI-STATUS";
        constexpr std::string_view http_400_bad_request_str = "400 BAD REQUEST";
        constexpr std::string_view http_401_unauthorized_str = "401 UNAUTHORIZED";
        constexpr std::string_view http_402_payment_required_str = "402 PAYMENT REQUIRED";
        constexpr std::string_view http_403_forbidden_str = "403 FORBIDDEN";
        constexpr std::string_view http_404_not_found_str = "404 NOT FOUND";
        constexpr std::string_view http_405_method_not_allowed_str = "405 METHOD NOT ALLOWED";
        constexpr std::string_view http_406_not_acceptable_str = "405 NOT ACCEPTABLE";
        constexpr std::string_view http_408_request_timeout_str = "408 REQUEST TIMEOUT";
        constexpr std::string_view http_415_unsupported_media_type_str = "415 UNSUPPORTED MEDIA TYPE";
        constexpr std::string_view http_500_internal_server_error_str = "500 INTERNAL SERVER ERROR";
        constexpr std::string_view http_501_not_implemented_str = "501 NOT IMPLEMENTED";
        constexpr std::string_view http_502_bad_gateway_str = "502 BAD GATEWAY";
        constexpr std::string_view http_503_service_unavailable_str = "503 SERVICE UNAVAILABLE";
        constexpr std::string_view http_504_gateway_timeout_str = "504 GATEWAY TIMEOUT";
    }

    enum class http_status_codes
    {
        http_100_continue = 100,
        http_200_ok = 200,
        http_204_no_content = 204,
        http_205_reset_content = 205,
        http_207_multistatus = 207,
        http_400_bad_request = 400,
        http_401_unauthorized = 401,
        http_402_payment_required = 402,
        http_403_forbidden = 403,
        http_404_not_found = 404,
        http_405_method_not_allowed = 405,
        http_406_not_acceptable = 406,
        http_408_request_timeout = 408,
        http_415_unsupported_media_type = 415,
        http_500_internal_server_error = 500,
        http_501_not_implemented = 501,
        http_502_bad_gateway = 502,
        http_503_service_unavailable = 503,
        http_504_gateway_timeout = 504,
    };

    std::string_view to_string(http_status_codes code);

}