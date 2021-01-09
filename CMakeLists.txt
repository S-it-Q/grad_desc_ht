cmake_minimum_required(VERSION 3.17)
project(grad_desc_ht)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wignored-attributes")

include_directories("include")
add_executable(grad_desc_ht src/main.cpp src/WorkgroupManager.hpp src/WorkgroupManager.cpp)
target_link_libraries(grad_desc_ht ${CMAKE_SOURCE_DIR}/lib/x64/libOpenCL.a)