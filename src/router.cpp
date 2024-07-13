#include "router.hpp"

// Adds a new route to the router
void Router::addRoute(const std::string& path, const std::string& method, void(*handler)(Request&, Response&)) {
    routes[path][method] = handler;
}

// Handles an incoming request
void Router::handleRequest(Request& request, Response& response) {
    if (routes.find(request.path) != routes.end() && routes[request.path].find(request.method) != routes[request.path].end()) {
        routes[request.path][request.method](request, response);
    } else {
        response.setStatus(404);
        response.setHeader("Content-Type", "text/plain");
        response.setBody("Not Found");
    }
}
