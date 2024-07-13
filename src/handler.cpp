#include "handler.hpp"
#include "json.hpp"
//#include <iostream>

void Handler::handleRoot(Request& req, Response& res) {
    res.setStatus(200);
    res.setHeader("Content-Type", "text/html");
    res.setBody("<html><body><h1>Welcome to the HTTP Server</h1></body></html>");
}

void Handler::handleEcho(Request& req, Response& res) {
    res.setStatus(200);
    res.setHeader("Content-Type", "text/plain");
    res.setBody(req.body);
}

void Handler::handleJson(Request& req, Response& res) {
    res.setStatus(200);
    res.setHeader("Content-Type", "application/json");
    std::map<std::string, std::string> jsonResponse = { {"message", "أحلى مسا يا قلب السيرفر"} };
    res.setBody(toJson(jsonResponse));
}
