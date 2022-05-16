cmake_minimum_required(VERSION 3.19)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 20)

find_package(SFML 2.5
        COMPONENTS
        system window graphics network audio REQUIRED)

add_executable(GameOfLife main.cpp GameBoard.h GameBoard.cpp)

target_link_libraries(GameOfLife sfml-graphics sfml-system sfml-window)
