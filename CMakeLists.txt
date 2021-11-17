cmake_minimum_required(VERSION 3.20)
project(soare_plus_plus)

set(CMAKE_CXX_STANDARD 20)

add_executable(soare_plus_plus
        main.cpp fenomen_meteorologic.cpp fenomen_meteorologic.h statistica.cpp statistica.h ploaie.cpp ploaie.h soare.cpp soare.h exceptii.cpp exceptii.h ceata.cpp ceata.h)

target_include_directories(soare_plus_plus PUBLIC include)
