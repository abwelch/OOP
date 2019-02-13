cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_FLAGS -std=c++14)
project(updatedWar)
#Add additional files to set with a space 
set(SOURCE main.cpp card.cpp deck.cpp warGame.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})