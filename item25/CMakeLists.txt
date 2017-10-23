cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp Widget.cpp Widget.h NastyWidget.cpp NastyWidget.h RandomType.cpp RandomType.h)
add_executable(item25 ${SOURCE_FILES})