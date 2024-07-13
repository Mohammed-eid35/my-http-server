#ifndef HANDLER_HPP
#define HANDLER_HPP

#include "request.hpp"
#include "response.hpp"

class Handler {
public:
    static void handleRoot(Request& req, Response& res);
    static void handleEcho(Request& req, Response& res);
    static void handleJson(Request& req, Response& res);
};

#endif
