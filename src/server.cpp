#include "server.hpp"
#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstring>

// Constructor: Initializes the server
Server::Server(int port, size_t num_threads) : port(port), thread_pool(num_threads) {
    setupServer();
    std::cout << "********** server constructor **********\n";
}

// Adds a new route
void Server::addRoute(const std::string& path, const std::string& method, void(*handler)(Request&, Response&)) {
    router.addRoute(path, method, handler);
}

// Adds a middleware function
void Server::use(std::function<void(Request&, Response&, std::function<void()>)> middleware) {
    middlewares.push_back(middleware);
}

// Starts the server
void Server::start() {
    std::cout << "Server is listening on port " << port << std::endl;
    while (true) {
        std::cout << "** server start > while(true) \n";
        socklen_t address_len = sizeof(address);
        std::cout << "** address: \n";
        int new_socket = accept(server_fd, (struct sockaddr*)&address, &address_len);
        std::cout << "*** new_socket: " << new_socket << "\n";
        if (new_socket < 0) {
            std::cerr << "Failed to accept connection" << std::endl;
            continue;
        }
        thread_pool.enqueue(&Server::handleRequest, this, new_socket);
    }
}

// Handles an incoming request
void Server::handleRequest(int new_socket) {
    char buffer[30000] = {0};
    read(new_socket, buffer, 30000);

    Request request(buffer);
    Response response;

    processMiddlewares(request, response, 0);

    std::string response_str = response.toString();
    send(new_socket, response_str.c_str(), response_str.length(), 0);
    close(new_socket);
}

// Processes middleware functions
void Server::processMiddlewares(Request& request, Response& response, size_t index) {
    if (index < middlewares.size()) {
        middlewares[index](request, response, [this, &request, &response, index] {
            processMiddlewares(request, response, index + 1);
        });
    } else {
        router.handleRequest(request, response);
    }
}

// Sets up the server socket
void Server::setupServer() {
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == 0) {
        throw std::runtime_error("Socket failed");
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        throw std::runtime_error("Bind failed");
    }

    if (listen(server_fd, 10) < 0) {
        throw std::runtime_error("Listen failed");
    }
}
