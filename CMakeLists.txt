cmake_minimum_required(VERSION 3.0.0)
project(openGL VERSION 0.1.0)

include(CTest)
enable_testing()


file(GLOB_RECURSE ImGui_SOURCES "vendor/imgui/*.cpp")
file(GLOB_RECURSE ImGui_HEADERS "vendor/imgui/*.h")

add_executable(openGLApp opengl.cpp Shader.cpp Shader.h vendor/stb_image/stb_image.h vendor/stb_image/stb_image.cpp Texture.cpp Texture.h Helpers.h ${ImGui_SOURCES} ${ImGui_HEADERS})

target_sources(openGLApp 
PRIVATE
IndexBuffer.cpp
VertexBuffer.cpp
Renderer.cpp
VertexArray.cpp
PUBLIC
IndexBuffer.h
VertexBuffer.h
Renderer.h
VertexBufferLayout.h
VertexArray.h
)


set(CMAKE_CXX_FLAGS "-Wall -Wextra -std=c++17 -fdump-tree-optimized")
set(CMAKE_CXX_FLAGS_DEBUG "-g  -O0 -pg -ggdb3")


set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(glfw)
target_link_libraries(openGLApp glfw)


find_package(OpenGL REQUIRED)
#target_include_directories(openGLApp ${OPENGL_INCLUDE_DIR})
target_link_libraries(openGLApp ${OPENGL_gl_LIBRARY})


find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
target_link_libraries(openGLApp ${GLEW_LIBRARIES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


target_include_directories(openGLApp PRIVATE vendor/stb_image)
target_include_directories(openGLApp PRIVATE vendor/glm)
target_include_directories(openGLApp PRIVATE vendor/imgui)
