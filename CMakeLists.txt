cmake_minimum_required(VERSION 3.20)
project(soare_plus_plus)

if (MSVC)
    add_compile_options(/W4)
else ()
    add_compile_options(-Wall -Wextra -pedantic -g)
    if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
        add_compile_options(-stdlib=libstdc++)
    endif ()
endif ()

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME}
        main.cpp fenomen_meteorologic.cpp fenomen_meteorologic.h statistica.cpp statistica.h ploaie.cpp ploaie.h soare.cpp soare.h exceptii.cpp exceptii.h ceata.cpp ceata.h furtuna.cpp furtuna.h)

target_include_directories(${PROJECT_NAME} PUBLIC include)


install(TARGETS ${PROJECT_NAME} DESTINATION bin)
