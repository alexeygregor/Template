cmake_minimum_required(VERSION 3.16)

add_executable(Shop main.cpp ${MY_INCLUDE_DIR}/Shop.h Shop.cpp)
target_include_directories(Shop PUBLIC ${MY_INCLUDE_DIR})