cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(Uniteller_HW)

find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    # Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update ${PROJECT_SOURCE_DIR}")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

ADD_SUBDIRECTORY(tests)
add_executable(Uniteller_HW main.cpp Indx_impl/Indx.cpp Indx_impl/El.cpp Indx_impl/El.h)


