#include "request.hpp"
#include <sstream>
//#include <iostream>

// Parses the raw HTTP request
Request::Request(const std::string& raw_request) {
    parseRequest(raw_request);
}

// Parses the HTTP request string
void Request::parseRequest(const std::string& raw_request) {
    std::istringstream stream(raw_request);
    std::string line;
    std::getline(stream, line);
    std::istringstream line_stream(line);

    line_stream >> method >> path;

    while (std::getline(stream, line) && line != "\r") {
        size_t colon = line.find(':');
        if (colon != std::string::npos) {
            std::string key = line.substr(0, colon);
            std::string value = line.substr(colon + 2, line.length() - colon - 3); // Remove colon and \r
            headers[key] = value;
        }
    }

    std::ostringstream body_stream;
    body_stream << stream.rdbuf();
    body = body_stream.str();
}
