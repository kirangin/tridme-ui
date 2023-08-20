#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include <core/BaseWindow.hpp>

namespace Tridme {
  class Application {
    public:
      Application(int argc, char** argv);
      ~Application();

      void setMainWindow(BaseWindow* window);
      void run();
  
    private:
      BaseWindow* m_mainWindow;
  };
};

#endif