project(example)

include_directories(../include)
include_directories(../vendors/glfw/include)
include_directories(../vendors/glad/include)
include_directories(../vendors/imgui)

add_executable(
  ${PROJECT_NAME}
  main.cpp
  MainWindow.cpp 
)

target_link_libraries(
  ${PROJECT_NAME} 
  TridmeUI
  GLAD 
  glfw 
  IMGUI
)