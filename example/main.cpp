#include <iostream>
#include <core/Application.hpp>
#include "MainWindow.hpp"

int main(int argc, char** argv) {

  MainWindow mainwindow("Test App", 1280, 720);
  Application* app = new Application(argc, argv);
  app->setMainWindow(&mainwindow);
  app->run();

  return 0;
}
