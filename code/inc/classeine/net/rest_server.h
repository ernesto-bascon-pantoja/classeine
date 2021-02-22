#pragma once

#include <memory>
#include <string_view>
#include <unordered_map>

#include "civetweb.h"

#include "classeine/core/entity.h"

#include "classeine/net/civetweb_tools.h"
#include "classeine/net/http_exception.h"
#include "classeine/net/http_status_codes.h"
#include "classeine/net/rest_controller.h"
#include "classeine/net/rest_path.h"



namespace classeine::net
{
    using namespace classeine::core;
    using namespace classeine::net;

    template <typename Domain>
    class rest_server : public entity<Domain>
    {
        using rest_controller_type = rest_controller<Domain>;
        using rest_endpoint_handler_type = rest_endpoint_handler<Domain>;

        mg_context* ctx;

        std::string app_name;

        std::unordered_map<std::string, std::unique_ptr<rest_controller_type>> controllers;


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

        template <typename RestController>
        void add_controller(std::unique_ptr<RestController>&& controller)
        {
            auto& name = controller->get_name();

            this->log_debug("Inserting controller: [", name, "]");

            controllers[name] = std::move(controller);
        }

        std::optional<std::reference_wrapper<rest_controller_type>> get_controller_by_path(const rest_path& path) const
        {
            auto name = std::string {path.get_controller_name() };
            auto controller_it = controllers.find(name);
            if (controller_it == controllers.end())
                return std::nullopt;

            return std::ref(*(controller_it->second));
        }

        std::optional<rest_endpoint_handler_type> find_request_handler(const http_request& request) const
        {
            rest_path path { request };

            auto optional_controller = get_controller_by_path(path);
            if (optional_controller)
            {

            }

            throw http_exception {
                http_status_codes::http_404_not_found,
                string_tools::build_string("Resource [", request.get_uri(), "] not found") };
        }

        int process_request(mg_connection& conn, const http_request& request)
        {
            std::cout << "URI: " << request.get_uri() << "\n";
            std::cout << "METHOD: " << to_string(request.get_method()) << "\n";

            auto optional_request_handler = find_request_handler(request);
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

            return the_rest_server.process_request(*conn, civetweb_tools::get_request(*conn));
        }
    };
}