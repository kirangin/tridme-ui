#include "MainWindow.hpp"

#ifndef IOSTREAM_INCLUDED
  #include <iostream>
#endif

MainWindow::MainWindow(std::string title, int width, int height) 
: BaseWindow(title, width, height) { }
  
MainWindow::~MainWindow() { }

void MainWindow::onInit() { 
  this->setEnableDockspace(true);

  ImGuiIO& io = ImGui::GetIO();
  m_poppins24 = io.Fonts->AddFontFromFileTTF("./deps/fonts/Poppins/Poppins-Regular.ttf", 32.0f);

  m_username = new LineEdit("Nama");
  m_username->setPlaceholderText("johndoe");
  m_username->setMaxLength(8);

  m_password = new LineEdit("Password");
  m_password->setPlaceholderText("********");
  m_password->hideCharacter(true);

  m_reason = new TextEdit("Reason");
  m_reason->setPlaceholderText("Reason for joining");

  HBoxLayout* hboxRow1 = new HBoxLayout();
  // HBoxLayout* hboxRow2 = new HBoxLayout();
  // VBoxLayout* vbox = new VBoxLayout();

  // addComponent(m_username);
  // addComponent(m_password);
  // addComponent(m_reason);
  hboxRow1->addComponent(m_username);
  hboxRow1->addComponent(m_password);
  // hboxRow2->addComponent(m_reason);

  // vbox->addLayout(hboxRow1);
  // vbox->addLayout(hboxRow2);

  // m_username->onEnterPressed.connect([this] { onUsernameEntered(); });
  // m_password->onEnterPressed.connect([this] { onPasswordEntered(); });
  setLayout(hboxRow1);
}

void MainWindow::onUpdate(float dt) {
  bool active = true;
  ImGui::ShowDemoWindow(&active);
}

void MainWindow::onDestroy() {
  
}

void MainWindow::onButtonClicked() {
  std::string username = m_username->getText();
  std::string password = m_password->getText();

  if ((username.compare("naufaladrna08")) == 0 && (password.compare("123456") == 0)) {
    m_text->setText("Login Success");
  } else {
    m_text->setText("Wrong username or password");
  }
}

void MainWindow::onUsernameEntered() {
  /* Validate username length */
  std::string username = m_username->getText();

  if (username.length() < 6) {
    m_text->setText("Username must be at least 6 characters");
  } else {
    m_text->setText("Username is valid");
  }
}

void MainWindow::onPasswordEntered() {
  /* Validate password length */
  std::string password = m_password->getText();

  if (password.length() < 6) {
    m_text->setText("Password must be at least 6 characters");
  } else {
    m_text->setText("Password is valid");
  }
}