include_directories(../include)
include_directories(../vendors/glfw/include)
include_directories(../vendors/glad/include)
include_directories(../vendors/imgui)

add_library(
  TridmeUI
  core/Application.cpp
  core/BaseWindow.cpp
  core/Signal.cpp
  components/Object.cpp
  components/Text.cpp
  components/Button.cpp
  components/LineEdit.cpp
  components/TextEdit.cpp
  components/Layout.cpp
  components/HBoxLayout.cpp
  components/VBoxLayout.cpp
)

target_include_directories(
  TridmeUI
  PUBLIC ${PROJECT_SOURCE_DIR}/include
)