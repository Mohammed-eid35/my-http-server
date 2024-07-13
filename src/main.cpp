#include "server.hpp"
#include "middleware.hpp"
#include "handler.hpp"
#include <iostream>

int main() {
    std::cout << "********** main function **********\n";
    Server server(8080, 4);

    // Add routes
    server.addRoute("/", "GET", Handler::handleRoot);
    server.addRoute("/echo", "POST", Handler::handleEcho);
    server.addRoute("/json", "POST", Handler::handleJson);

    // Add middlewares
    server.use(Middleware::logRequests());
//    server.use(Middleware::authorize());

    server.start();

    return 0;
}
