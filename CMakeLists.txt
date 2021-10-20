cmake_minimum_required(VERSION 3.20)
project(soare_plus_plus)

set(CMAKE_CXX_STANDARD 20)

add_executable(soare_plus_plus
        main.cpp)

target_include_directories(soare_plus_plus PUBLIC include)
