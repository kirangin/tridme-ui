#include <core/Application.hpp>
using namespace Tridme;

Application::Application(int argc, char** argv) {
  if (glfwInit() == GL_FALSE) {
    fprintf(stderr, "Cannot initialize GLFW\n");
  } else {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  }

  /* TODO: proses arguments */
}

Application::~Application() { 
  glfwTerminate();
  delete this->m_mainWindow;
}

void Application::setMainWindow(BaseWindow* window) {
  this->m_mainWindow = window;
}

void Application::run() {
  this->m_mainWindow->init();
  this->m_mainWindow->theme();
  
  this->m_mainWindow->onInit();

  float deltaTime = 0.0f;
  float lastFrame = 0.0f; 

  while (!this->m_mainWindow->isRunning()) {
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;  

    this->m_mainWindow->newFrame();
    this->m_mainWindow->onUpdate(deltaTime);
    this->m_mainWindow->renderWidgets();

    this->m_mainWindow->update();
  }

  this->m_mainWindow->onDestroy();
  this->m_mainWindow->destroy();
}
