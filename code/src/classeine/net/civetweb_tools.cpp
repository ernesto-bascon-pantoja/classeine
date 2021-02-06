#include "classeine/net/civetweb_tools.h"

#include "civetweb.h"

classeine::net::http_request
classeine::net::civetweb_tools::get_request(const mg_connection& conn)
{
    return { *mg_get_request_info(&conn) };
}