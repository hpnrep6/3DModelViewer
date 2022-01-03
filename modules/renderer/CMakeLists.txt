cmake_minimum_required(VERSION 3.1)

project(JRenderer)
file(GLOB_RECURSE SRC src/*.cpp src/*.hpp include/*.hpp)

add_library(${PROJECT_NAME} ${SRC})
include_directories(include)
target_include_directories(${PROJECT_NAME} INTERFACE include)
target_link_directories(${PROJECT_NAME} INTERFACE include)

# glfw
add_subdirectory(thirdparty/glfw)
target_link_libraries(${PROJECT_NAME} glfw)

# OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} ${OPENGL_gl_LIBRARY})
set(OpenGL_GL_PREFERENCE GLVND)

# glew
add_subdirectory(thirdparty/glew)
target_link_libraries(${PROJECT_NAME} libglew_static)

# glm
add_subdirectory(thirdparty/glm)
target_link_libraries(${PROJECT_NAME} glm)

# stb
add_subdirectory(thirdparty/stb)
target_link_libraries(${PROJECT_NAME} stb)

# gltf
add_subdirectory(thirdparty/tinygltf)
target_link_libraries(${PROJECT_NAME} tinygltf)

# assimp
add_subdirectory(thirdparty/assimp)
target_link_libraries(${PROJECT_NAME} assimp)