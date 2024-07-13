#ifndef SERVER_HPP
#define SERVER_HPP

#include "router.hpp"
#include "request.hpp"
#include "response.hpp"
#include "thread_pool.hpp"
#include <string>
#include <functional>
#include <vector>
#include <netinet/in.h>

class Server {
public:
    Server(int port, size_t num_threads);
    void start();
    void addRoute(const std::string& path, const std::string& method, void(*handler)(Request&, Response&));
    void use(std::function<void(Request&, Response&, std::function<void()>)> middleware);

private:
    int port;
    int server_fd;
    struct sockaddr_in address;
    Router router;
    ThreadPool thread_pool;
    std::vector<std::function<void(Request&, Response&, std::function<void()>)>> middlewares;

    void handleRequest(int new_socket);
    void processMiddlewares(Request& request, Response& response, size_t index);
    void setupServer();
};

#endif
