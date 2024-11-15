cmake_minimum_required(VERSION 3.16)

add_executable(Register main.cpp ${MY_INCLUDE_DIR}/Register.h Register.cpp)
target_include_directories(Register PUBLIC ${MY_INCLUDE_DIR})