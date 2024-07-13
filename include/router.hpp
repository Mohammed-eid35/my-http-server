#ifndef ROUTER_HPP
#define ROUTER_HPP

#include "request.hpp"
#include "response.hpp"
#include <string>
#include <unordered_map>
#include <functional>

class Router {
public:
    void addRoute(const std::string& path, const std::string& method, void(*handler)(Request&, Response&));
    void handleRequest(Request& request, Response& response);

private:
    std::unordered_map<std::string, std::unordered_map<std::string, void(*)(Request&, Response&)>> routes;
};

#endif
