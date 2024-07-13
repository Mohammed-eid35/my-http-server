cmake_minimum_required(VERSION 3.10)
project(http_server)

set(CMAKE_CXX_STANDARD 17)

add_executable(http_server
        src/main.cpp
        src/request.cpp
        src/response.cpp
        src/router.cpp
        src/server.cpp
        src/thread_pool.cpp
        src/handler.cpp
        src/json.cpp
        src/middleware.cpp
        src/request.cpp
)

target_include_directories(http_server PRIVATE include)

find_package(Threads REQUIRED)
target_link_libraries(http_server PRIVATE Threads::Threads)
