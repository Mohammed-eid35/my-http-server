#include "response.hpp"
#include <sstream>
#include <iostream>

// Constructor
Response::Response() : status(200) {
    std::cout << "**********response constructor **********\n";
}

// Sets the HTTP status code
void Response::setStatus(int status) {
    this->status = status;
}

// Sets an HTTP header
void Response::setHeader(const std::string& key, const std::string& value) {
    headers[key] = value;
}

// Sets the response body
void Response::setBody(const std::string& body) {
    this->body = body;
}

// Converts the response to a string for sending
std::string Response::toString() const {
    std::ostringstream response;
    response << "HTTP/1.1 " << status << " OK\r\n";
    for (const auto& header : headers) {
        response << header.first << ": " << header.second << "\r\n";
    }
    response << "\r\n" << body;
    return response.str();
}
