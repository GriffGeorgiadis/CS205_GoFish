cmake_minimum_required(VERSION 3.8)
project(CS205_GoFish_master)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/Card.cpp src/Card.h src/Deck.cpp src/Deck.h src/Player.cpp src/Player.h)

add_executable(CS205_GoFish_master ${SOURCE_FILES})