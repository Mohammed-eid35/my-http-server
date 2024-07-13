#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include <string>
#include <unordered_map>

class Response {
public:
    Response();
    void setStatus(int status);
    void setHeader(const std::string& key, const std::string& value);
    void setBody(const std::string& body);
    std::string toString() const;

private:
    int status;
    std::unordered_map<std::string, std::string> headers;
    std::string body;
};

#endif
