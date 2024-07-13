#include "middleware.hpp"
#include <iostream>

// Middleware to log requests
MiddlewareFunction Middleware::logRequests() {
    return [](Request& req, Response& res, const std::function<void()>& next) {
        std::cout << "Request: " << req.method << " " << req.path << std::endl;
        next();
    };
}

// Middleware to authorize requests (dummy implementation)
MiddlewareFunction Middleware::authorize() {
    return [](Request& req, Response& res, const std::function<void()>& next) {
        if (req.headers.find("Authorization") != req.headers.end()) {
            next();
        } else {
            res.setStatus(403);
            res.setHeader("Content-Type", "text/plain");
            res.setBody("Forbidden: Authorization required");
        }
    };
}
