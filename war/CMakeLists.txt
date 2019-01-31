cmake_minimum_required(VERSION 3.0)
project(war)
#Add additional files to set with a space 
set(SOURCE main.cpp card.cpp warGame.cpp)
add_executable(${PROJECT_NAME} ${SOURCE})