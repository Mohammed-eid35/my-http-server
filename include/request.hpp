#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <string>
#include <unordered_map>

class Request {
public:
    std::string method;
    std::string path;
    std::unordered_map<std::string, std::string> headers;
    std::string body;

    Request(const std::string& raw_request);

private:
    void parseRequest(const std::string& raw_request);
};

#endif
