#ifndef MIDDLEWARE_HPP
#define MIDDLEWARE_HPP

#include "request.hpp"
#include "response.hpp"
#include <functional>
#include <vector>

using MiddlewareFunction = std::function<void(Request&, Response&, std::function<void()>)>;

class Middleware {
public:
    static MiddlewareFunction logRequests();
    static MiddlewareFunction authorize();
};

#endif
