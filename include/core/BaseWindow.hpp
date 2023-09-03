#ifndef BASEWINDOW_HPP
#define BASEWINDOW_HPP
#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <stack>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <etc/FontAwesome.hpp>
#include <misc/cpp/imgui_stdlib.h>
#include <components/Layout.hpp>
#include <components/MenuBar.hpp>
#include <components/ModalDialog.hpp>
using namespace Tridme;
using namespace Tridme::UI;
using namespace Tridme::Storage;

namespace Tridme {
  class BaseWindow {
    public:
      BaseWindow(std::string title, int width, int height);
      ~BaseWindow();

      virtual void onInit() { }
      virtual void onUpdate(float dt) { }
      virtual void onDestroy() { }

      inline bool isRunning() { return glfwWindowShouldClose(this->m_window); }

      void init();
      void update();
      void destroy();
      void newFrame();
      void renderWidgets();
      void theme();
      void setEnableDockspace(bool enable);
      void addComponent(Object* obj);
      void addModal(ModalDialog* modal);
      void setMenuBar(MenuBar* menuBar);
      void setLayout(Layout* layout);

      inline int getDialogCounter() { return this->m_dialogCounter; }
      inline void increaseDialogCounter() { this->m_dialogCounter += 1; }

    private:
      std::string m_title;
      int         m_width;
      int         m_height;
      int         m_dialogCounter = 0;
      Layout*     m_layout = nullptr;
      GLFWwindow* m_window;

      bool m_dockspaceEnabled = false;
      bool m_windowOpened = true;
      std::unordered_map<std::string, Vector<std::string>> m_componentIds;
      MenuBar* m_menuBar = nullptr;
      Vector<ModalDialog*> m_stackedModalDialog;

      /* ImGui dan Dockingnya */
      bool m_optFullscreen = true;
      bool m_optPadding = false;
      ImGuiDockNodeFlags m_dockspaceFlags = ImGuiDockNodeFlags_None;
      ImGuiWindowFlags m_windowFlags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
      bool m_hasMenu = false;
  };
} // namespace Tridme


#endif