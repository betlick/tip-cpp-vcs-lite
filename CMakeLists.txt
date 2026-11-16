cmake_minimum_required(VERSION 3.20)

project(VCSLite VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)
include(GNUInstallDirs)

add_subdirectory(src)

if(BUILD_TESTING)
    add_subdirectory(tests)
endif()
