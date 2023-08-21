#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP
#include <core/BaseWindow.hpp>
#include <components/Object.hpp>
#include <components/Button.hpp>
#include <components/Text.hpp>
#include <components/LineEdit.hpp>
#include <components/TextEdit.hpp>
#include <components/HBoxLayout.hpp>
#include <components/VBoxLayout.hpp>
using namespace Tridme;
using namespace Tridme::UI;

/* Remove latter */
#include <stack>

class MainWindow : public BaseWindow {
  public:
    MainWindow(std::string title, int width, int height);
    ~MainWindow();

    void onInit() override;
    void onUpdate(float dt) override;
    void onDestroy() override;

    /* Modes */
    void modeBasic();
    void modeAdvanced();
    void input(char* c);

    void onButtonClicked();
    void onUsernameEntered();
    void onPasswordEntered();

  private:
    bool m_myToolActive = false;

    ImFont*   m_poppins24;
    Button*   m_buttonPlay;
    Text*     m_text;
    LineEdit* m_username;
    LineEdit* m_password;
    TextEdit* m_reason;
};

#endif