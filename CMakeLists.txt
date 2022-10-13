cmake_minimum_required(VERSION 3.23)
project(untitled)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled main.cpp src/ball.cpp include/ball.h src/paddle.cpp include/paddle.h src/ScoreBoard.cpp include/ScoreBoard.h )

target_link_libraries(untitled sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)