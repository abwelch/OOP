cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_FLAGS -std=c++14)
project(JSON)
#Add additional files to set with a space 
set(SOURCE driver.cpp modelRedditPost.cpp json_json.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})