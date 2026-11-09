project(physics-module)

add_library(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PUBLIC .)

add_subdirectory(core)