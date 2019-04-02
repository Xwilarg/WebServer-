cmake_minimum_required(VERSION 3.7)
project(WebServer++)

find_package(cpprestsdk REQUIRED)

add_executable(WebServer++ src/main.cpp)
target_link_libraries(WebServer++ PRIVATE cpprestsdk::cpprest)