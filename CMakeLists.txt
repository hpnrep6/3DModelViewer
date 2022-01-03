cmake_minimum_required(VERSION 3.1)

project(AFract)

add_executable(${PROJECT_NAME} src/main.cpp)

add_subdirectory(modules/renderer)
target_include_directories(${PROJECT_NAME} PUBLIC JRenderer)
target_link_directories(${PROJECT_NAME} PRIVATE JRenderer)
target_link_libraries(${PROJECT_NAME} JRenderer)