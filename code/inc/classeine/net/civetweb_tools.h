#pragma once

#include "http_request.h"

struct mg_connection;

namespace classeine::net::civetweb_tools
{
    http_request get_request(const mg_connection& conn);
}