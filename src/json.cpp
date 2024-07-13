#include "json.hpp"
#include <sstream>

// Converts a map to a JSON string
std::string toJson(const std::map<std::string, std::string>& data) {
    std::ostringstream oss;
    oss << "{";
    for (auto it = data.begin(); it != data.end(); ++it) {
        if (it != data.begin()) {
            oss << ",";
        }
        oss << "\"" << it->first << "\":\"" << it->second << "\"";
    }
    oss << "}";
    return oss.str();
}
