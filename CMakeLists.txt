cmake_minimum_required(VERSION 3.24)
project(Project3)

set(CMAKE_CXX_STANDARD 20)

add_executable(Project3 main.cpp)
add_library(EasyBMP EasyBMP.cpp EasyBMP.h)
target_include_directories(Project3 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/path/to/easybmp)
target_link_libraries(Project3 PRIVATE EasyBMP)
