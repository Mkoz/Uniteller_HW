project(UnitTests)

set(CMAKE_CXX_STANDARD 17)
cmake_minimum_required(VERSION 3.16)

################################
# Indx_impl
################################
include_directories(${UnitTests_SOURCE_DIR}/../Indx_impl)

################################
# GTest
################################
ADD_SUBDIRECTORY(gtest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

################################
# Unit Tests
################################
# Add test cpp file
add_executable( UnitTests test.cpp ${UnitTests_SOURCE_DIR}/../Indx_impl/Indx.cpp ${UnitTests_SOURCE_DIR}/../Indx_impl/El.cpp)
# Link test executable against gtest & gtest_main
target_link_libraries(UnitTests gtest gtest_main)
add_test( UnitTests ./UnitTests)
