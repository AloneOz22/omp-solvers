cmake_minimum_required(VERSION 3.5)

project(omp-solvers LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    "include"
    "src"
)
add_subdirectory(linear-algebra)
include_directories(omp-solvers linear-algebra/include)

set(SRCs src/solvers.cpp src/main.cpp)
set(HEADERs include/solvers.hpp)


set(launcher_NAME "omp_solvers")


ADD_EXECUTABLE(${launcher_NAME} ${SRCs} ${HEADERs})
TARGET_LINK_LIBRARIES(${launcher_NAME} linear-algebra)
