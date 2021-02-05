#pragma once

#include <string_view>

#include "civetweb.h"

#include "classeine/core/entity.h"

#include "classeine/net/civetweb_utils.h"



namespace classeine::net
{
    using namespace classeine::core;
    using namespace classeine::net;

    template <typename Domain>
    class rest_server : public entity<Domain>
    {
        mg_context* ctx;

        std::string app_name;

    public:
        template <typename String>
        rest_server(Domain& parent_domain, String&& app_name)
            : entity<Domain>{parent_domain, "rest_server"},
              ctx{nullptr},
              app_name{std::forward<String>(app_name)}
        {
            mg_init_library(0);
        }

        ~rest_server()
        {
            if (ctx !=  nullptr)
            {
                mg_stop(ctx);
            }

            mg_exit_library();
        }


        void start()
        {
            auto ports = this->get_conf().get_or_default("rest_server", "ports", "8080");
            this->log_info("Listening to ports [", ports, "]");

            const char* options[] = { "listening_ports", ports.data(), nullptr };

            ctx = mg_start(nullptr, nullptr, options);

            mg_set_request_handler(ctx, "", server_handler, this);
        }

        void add_controller()
        {

        }

        int process_request(mg_connection& conn, const http_request& request)
        {
//            auto optional_controller = find_controller(request);
//            if (optional_controller.has_value())
//            {
//                std::string result = optional_controller->process_request(request);
//                mg_send_http_ok(&conn, "application/json", 0);
//                return 200;
//            }

            mg_send_http_ok(&conn, "application/json", 0);
            return 404;
        }

    private:
        static int server_handler(mg_connection* conn, void* rest_server_ptr)
        {
            auto& the_rest_server = *reinterpret_cast<rest_server<Domain>*>(rest_server_ptr);

            return the_rest_server.process_request(*conn, civetweb_utils::get_request(*conn));
        }
    };
}