#pragma once

#include <string_view>

#include "classeine/core/entity.h"

#include "civetweb.h"

namespace classeine::net
{
    using namespace classeine::core;

    template <typename Domain>
    class rest_server : public entity<Domain>
    {
        mg_context* ctx;

    public:
        rest_server(Domain& parent_domain)
            : entity<Domain>{parent_domain, "rest_server"},
              ctx{mg_start(NULL, 0, NULL)}
        {
            mg_init_library(0);
        }

        ~rest_server()
        {
            mg_stop(ctx);
            mg_exit_library();
        }

        void start()
        {
            mg_set_request_handler(ctx, "/hello", handler, (void*) "Hello world");
        }

        void add_controller()
        {

        }

    private:
        static int handler(struct mg_connection *conn, void *ignored)
        {
            const std::string_view msg = "Hello world";

            auto len = msg.length();

            mg_send_http_ok(conn, "text/plain", len);
            mg_write(conn, msg.data(), len);

            return 200;
        }
    };
}