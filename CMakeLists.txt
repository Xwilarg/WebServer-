cmake_minimum_required(VERSION 3.7)
project(WebServer++)

find_package(cpprestsdk REQUIRED)

if (WIN32)
	SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /W4")
endif (WIN32)
if (UNIX)
	SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -Weffc++")
endif (UNIX)

include_directories(inc)
add_executable(WebServer++ src/main.cpp src/WebServer.cpp)
target_link_libraries(WebServer++ PRIVATE cpprestsdk::cpprest)