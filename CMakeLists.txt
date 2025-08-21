cmake_minimum_required(VERSION 3.1)
project(DSA)

 
add_library(
    ${PROJECT_NAME} INTERFACE
)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_VISIBILITY_PRESET hidden)

target_include_directories(
    ${PROJECT_NAME}
    INTERFACE 
    DSA/
)