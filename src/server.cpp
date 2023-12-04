#include "server.h"
#include "www_index.h"
#include "www_mastercss.h"

std::shared_ptr<http_response> hello_world_resource::render(const http_request&) {

        std::shared_ptr<http_response> response = std::shared_ptr<http_response>(new string_response( reinterpret_cast< char const*>(www_index) ));
        response->with_header("Content-Type", "text/html");
        return response;
}

std::shared_ptr<http_response> master_css::render(const http_request&) {

        std::shared_ptr<http_response> response = std::shared_ptr<http_response>(new string_response( reinterpret_cast< char const*>(www_mastercss) ));        
        response->with_header("Content-Type", "text/css");
        return response;
}

