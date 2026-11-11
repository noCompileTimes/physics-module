project(physics-module LANGUAGES CXX)

add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC .)

add_subdirectory(core)