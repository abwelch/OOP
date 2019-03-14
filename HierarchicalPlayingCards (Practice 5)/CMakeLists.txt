cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_FLAGS -std=c++17)
project(hierarchyCards)
#Add additional files to set with a space 
set(SOURCE main.cpp card.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})