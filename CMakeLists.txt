cmake_minimum_required(VERSION 3.19)
project(project_2)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5
        COMPONENTS
        system window graphics network audio REQUIRED)

add_executable(project_2 main.cpp GameBoard.h GameBoard.cpp)

target_link_libraries(project_2 sfml-graphics sfml-system sfml-window)