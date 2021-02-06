#include "classeine/net/http_method.h"


constexpr std::string_view http_method_get_string = "GET";
constexpr std::string_view http_method_head_string = "HEAD";
constexpr std::string_view http_method_post_string = "POST";
constexpr std::string_view http_method_put_string = "PUT";
constexpr std::string_view http_method_delete_string = "DELETE";
constexpr std::string_view http_method_trace_string = "TRACE";
constexpr std::string_view http_method_options_string = "OPTIONS";
constexpr std::string_view http_method_connect_string = "CONNECT";

classeine::net::http_method
classeine::net::from_string(const std::string_view& str)
{
    if (str == http_method_get_string)     return http_method::get;
    if (str == http_method_head_string)    return http_method::head;
    if (str == http_method_post_string)    return http_method::post;
    if (str == http_method_put_string)     return http_method::put;
    if (str == http_method_delete_string)  return http_method::del;
    if (str == http_method_trace_string)   return http_method::trace;
    if (str == http_method_options_string) return http_method::options;
    if (str == http_method_connect_string) return http_method::connect;

    return http_method::unknown;
}

std::string_view
classeine::net::to_string(classeine::net::http_method method)
{
    switch (method)
    {
        case http_method::get:      return http_method_get_string;
        case http_method::head:     return http_method_head_string;
        case http_method::post:     return http_method_post_string;
        case http_method::put:      return http_method_put_string;
        case http_method::del:      return http_method_delete_string;
        case http_method::trace:    return http_method_trace_string;
        case http_method::options:  return http_method_options_string;
        case http_method::connect:  return http_method_connect_string;
    }

    return "unknown";
}
