#include "MainWindow.hpp"

#ifndef IOSTREAM_INCLUDED
  #include <iostream>
#endif

MainWindow::MainWindow(std::string title, int width, int height) 
: BaseWindow(title, width, height) { }
  
MainWindow::~MainWindow() { }

void MainWindow::onInit() { 
  m_modalOpen = new ModalDialog(*this);
  m_openFile = new Button("Open File");
 
  m_username = new LineEdit("Nama");
  m_username->setPlaceholderText("johndoe");
  m_username->setMaxLength(8);

  m_password = new LineEdit("Password");
  m_password->setPlaceholderText("********");
  m_password->hideCharacter(true);

  m_reason = new TextEdit("Reason");
  m_reason->setPlaceholderText("Reason for joining");

  HBoxLayout* hboxRow1 = new HBoxLayout();
  HBoxLayout* hboxRow2 = new HBoxLayout();
  VBoxLayout* vbox = new VBoxLayout();

  vbox->addComponent(m_username);
  vbox->addComponent(m_password);
  hboxRow2->addComponent(m_reason);

  m_modalOpen->addLayout(hboxRow2);
  hboxRow1->addLayout(vbox);

  setLayout(hboxRow1);
  createMenu();
}

void MainWindow::onUpdate(float dt) {
  // bool active = true;
  // ImGui::ShowDemoWindow(&active);
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

void MainWindow::onOpenFileClicked() {
  ImGui::OpenPopup("Delete?");
}

void MainWindow::createMenu() {
  Menu* menuFile = new Menu("File");
  menuBar()->addMenu(menuFile);
  Menu* menuEdit = new Menu("Edit");
  menuBar()->addMenu(menuEdit);

  menuFile->addItem("New", "CTRL+N", "new");
  menuFile->addItem("Open", "CTRL+O", "open");
  menuFile->addAction("open", [this] { 
    onNewFile();
  });
  menuFile->addItem("Save", "CTRL+S", "save");
  menuFile->addItem("Save As", "CTRL+SHIFT+S", "saveas");
  menuFile->addItem("Exit", "CTRL+Q", "exit");

  menuEdit->addItem("Undo", "CTRL+Z", "undo");
  menuEdit->addItem("Redo", "CTRL+Y", "redo");
  menuEdit->addItem("Cut", "CTRL+X", "cut");
  menuEdit->addItem("Copy", "CTRL+C", "copy");
  menuEdit->addItem("Paste", "CTRL+V", "paste");
  menuEdit->addItem("Delete", "DEL", "delete");
  menuEdit->addItem("Select All", "CTRL+A", "selectall");
}

void MainWindow::onNewFile() {
  std::cout << "Imagine there's no heaven" << std::endl;
}
