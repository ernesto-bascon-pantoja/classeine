#include "classeine/net/http_status_codes.h"


std::string_view
classeine::net::to_string(classeine::net::http_status_codes code)
{
    {
        switch (code)
        {
            case http_status_codes::http_100_continue:                  return http_status_code_names::http_100_continue_str;
            case http_status_codes::http_200_ok:                        return http_status_code_names::http_200_ok_str;
            case http_status_codes::http_204_no_content:                return http_status_code_names::http_204_no_content_str;
            case http_status_codes::http_205_reset_content:             return http_status_code_names::http_205_reset_content_str;
            case http_status_codes::http_207_multistatus:               return http_status_code_names::http_207_multistatus_str;
            case http_status_codes::http_400_bad_request:               return http_status_code_names::http_400_bad_request_str;
            case http_status_codes::http_401_unauthorized:              return http_status_code_names::http_401_unauthorized_str;
            case http_status_codes::http_402_payment_required:          return http_status_code_names::http_402_payment_required_str;
            case http_status_codes::http_403_forbidden:                 return http_status_code_names::http_403_forbidden_str;
            case http_status_codes::http_404_not_found:                 return http_status_code_names::http_404_not_found_str;
            case http_status_codes::http_405_method_not_allowed:        return http_status_code_names::http_405_method_not_allowed_str;
            case http_status_codes::http_406_not_acceptable:            return http_status_code_names::http_406_not_acceptable_str;
            case http_status_codes::http_408_request_timeout:           return http_status_code_names::http_408_request_timeout_str;
            case http_status_codes::http_415_unsupported_media_type:    return http_status_code_names::http_415_unsupported_media_type_str;
            case http_status_codes::http_500_internal_server_error:     return http_status_code_names::http_500_internal_server_error_str;
            case http_status_codes::http_501_not_implemented:           return http_status_code_names::http_501_not_implemented_str;
            case http_status_codes::http_502_bad_gateway:               return http_status_code_names::http_502_bad_gateway_str;
            case http_status_codes::http_503_service_unavailable:       return http_status_code_names::http_503_service_unavailable_str;
            case http_status_codes::http_504_gateway_timeout:           return http_status_code_names::http_504_gateway_timeout_str;
        }

        return "[Unknown]";
    }
}