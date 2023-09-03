cmake_minimum_required(VERSION 3.0.0)
project(TridmeCore VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(include)
include_directories(vendors/glfw/include)
include_directories(vendors/glad/include)
include_directories(vendors/imgui)

add_subdirectory(vendors/glfw)
add_subdirectory(vendors/glad)
add_subdirectory(vendors/imgui)

# Compile project source
add_subdirectory(src)

# Compile example
add_subdirectory(example)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
