cmake_minimum_required(VERSION 3.5)

project(omp_solvers LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    "include"
    "src"
)
add_subdirectory(linear_algebra)
include_directories(omp_solvers linear_algebra/include)

set(SRCs src/solvers.cpp src/main.cpp)
set(HEADERs include/solvers.hpp)


set(launcher_NAME "omp_solvers")


ADD_EXECUTABLE(${launcher_NAME} ${SRCs} ${HEADERs})
TARGET_LINK_LIBRARIES(${launcher_NAME} linear_algebra)
