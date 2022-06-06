cmake_minimum_required(VERSION 3.16)
project(Uniteller_HW)

set(CMAKE_CXX_STANDARD 17)

add_executable(Uniteller_HW main.cpp Indx_impl/Indx.cpp Indx_impl/El.cpp Indx_impl/El.h tests)