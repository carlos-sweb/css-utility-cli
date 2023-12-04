#ifndef SERVER_H
#define SERVER_H

#include <httpserver.hpp>
#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;
using namespace httpserver;
class hello_world_resource : public http_resource {
    public:        
        std::shared_ptr<http_response> render(const http_request&);
};
class master_css : public http_resource {
    public:        
        std::shared_ptr<http_response> render(const http_request&);
};
#endif //SERVER_H