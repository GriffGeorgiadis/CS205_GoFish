cmake_minimum_required(VERSION 3.8)
project(CS205_GoFish_master)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/main.cpp src/card.cpp src/card.h src/player.cpp src/player.h)

add_executable(CS205_GoFish_master ${SOURCE_FILES})