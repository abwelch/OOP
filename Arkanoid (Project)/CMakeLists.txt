
cmake_minimum_required(VERSION 3.8)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(SFML COMPONENTS graphics window system)
include_directories(${SFML_INCLUDE_DIR})

add_executable(arkanoid main.cpp Paddle.cpp Ball.cpp Background.hpp Blocky.cpp Instance.cpp Textures.cpp)
target_link_libraries(arkanoid ${SFML_LIBRARIES})
