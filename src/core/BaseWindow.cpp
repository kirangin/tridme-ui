#include <core/BaseWindow.hpp>
using namespace Tridme;

BaseWindow::BaseWindow(std::string title, int width, int height) 
: m_title(title),
  m_width(width),
  m_height(height) {

}
BaseWindow::~BaseWindow() {
  delete m_layout;
}

void BaseWindow::init() {
  // glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
  m_window = glfwCreateWindow(this->m_width, this->m_height, this->m_title.c_str(), nullptr, nullptr);

  if (m_window == nullptr) {
    fprintf(stderr, "Cannot create GLFW window\n");
    glfwTerminate();
    // die
  }

  glfwMakeContextCurrent(m_window);

  /* OpenGL function */
  if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
    fprintf(stderr, "Cannot load OpenGL\n");
    glfwTerminate();
    // die
  }

  /* Initialize ImGUI */
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO(); (void)io;

  io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
  io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
  // io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

  ImGui_ImplGlfw_InitForOpenGL(m_window, true);
  ImGui_ImplOpenGL3_Init("#version 330");
}

void BaseWindow::update() {
  glfwPollEvents();
  glfwSwapBuffers(m_window);
}

void BaseWindow::destroy() {
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();

  glfwDestroyWindow(m_window);
  glfwTerminate();
}

void BaseWindow::newFrame() {
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();
}

void BaseWindow::renderWidgets() {
  ImGuiIO& io = ImGui::GetIO();

  const ImGuiViewport* viewport = ImGui::GetMainViewport();
  ImGui::SetNextWindowPos(viewport->WorkPos);
  ImGui::SetNextWindowSize(viewport->WorkSize);
  ImGui::SetNextWindowViewport(viewport->ID);
  ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
  ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
  m_windowFlags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
  m_windowFlags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

  if (m_dockspaceEnabled) {
    if (!m_hasMenu) {
      m_windowFlags |= ImGuiWindowFlags_MenuBar;
    }

    /* Remove dockspace padding */
    ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
    ImGui::Begin("DockSpace Demo", &m_optFullscreen, m_windowFlags);
    ImGui::PopStyleVar();

      if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable) {
        ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
        ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), m_dockspaceFlags);
      }

      ImGui::Begin("MainWindow", &m_windowOpened);
      if (m_layout != nullptr)
        m_layout->render();
      ImGui::End();

    ImGui::End();
  } else {
    m_windowFlags  = ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
    m_windowFlags |= ImGuiWindowFlags_AlwaysVerticalScrollbar;

    ImGui::Begin("MainWindow", &m_windowOpened, m_windowFlags);
    m_layout->render();
    ImGui::End();
  }

  // ImGui::ShowDemoWindow(&m_windowOpened);

  ImGui::PopStyleVar();
  ImGui::PopStyleVar();
  
  ImGui::Render();
  int display_w, display_h;
  glfwGetFramebufferSize(m_window, &display_w, &display_h);
  glViewport(0, 0, display_w, display_h);
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

  if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
    GLFWwindow* backup_current_context = glfwGetCurrentContext();
    ImGui::UpdatePlatformWindows();
    ImGui::RenderPlatformWindowsDefault();
    glfwMakeContextCurrent(backup_current_context);
  }
}

void BaseWindow::theme() {
  /* Fonts */
  ImFontConfig config;
  float iconFontSize = 22.0f * 2.0f / 3.0f;
  ImGuiIO& io = ImGui::GetIO();

  config.MergeMode = true;
  config.GlyphMinAdvanceX = 13.0f;
  static const ImWchar iconRanges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };

  io.Fonts->AddFontFromFileTTF("./deps/fonts/Poppins/Poppins-Medium.ttf", 22.0f);
  io.Fonts->AddFontFromFileTTF(FONT_ICON_FILE_NAME_FAS, iconFontSize, &config, iconRanges);

  /* Colors */
  ImVec4* colors = ImGui::GetStyle().Colors;
  colors[ImGuiCol_Text]                   = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
  colors[ImGuiCol_TextDisabled]           = ImVec4(0.50f, 0.50f, 0.50f, 1.00f);
  colors[ImGuiCol_WindowBg]               = ImVec4(0.06f, 0.06f, 0.06f, 0.94f);
  colors[ImGuiCol_ChildBg]                = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
  colors[ImGuiCol_PopupBg]                = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
  colors[ImGuiCol_Border]                 = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
  colors[ImGuiCol_BorderShadow]           = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
  colors[ImGuiCol_FrameBg]                = ImVec4(0.36f, 0.36f, 0.36f, 0.54f);
  colors[ImGuiCol_FrameBgHovered]         = ImVec4(0.36f, 0.36f, 0.36f, 0.43f);
  colors[ImGuiCol_FrameBgActive]          = ImVec4(0.36f, 0.36f, 0.36f, 0.43f);
  colors[ImGuiCol_TitleBg]                = ImVec4(0.04f, 0.04f, 0.04f, 1.00f);
  colors[ImGuiCol_TitleBgActive]          = ImVec4(0.25f, 0.25f, 0.25f, 1.00f);
  colors[ImGuiCol_TitleBgCollapsed]       = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
  colors[ImGuiCol_MenuBarBg]              = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
  colors[ImGuiCol_ScrollbarBg]            = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
  colors[ImGuiCol_ScrollbarGrab]          = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
  colors[ImGuiCol_ScrollbarGrabHovered]   = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
  colors[ImGuiCol_ScrollbarGrabActive]    = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
  colors[ImGuiCol_CheckMark]              = ImVec4(0.00f, 0.59f, 0.90f, 1.00f);
  colors[ImGuiCol_SliderGrab]             = ImVec4(0.00f, 0.59f, 0.90f, 1.00f);
  colors[ImGuiCol_SliderGrabActive]       = ImVec4(0.00f, 0.59f, 0.90f, 1.00f);
  colors[ImGuiCol_Button]                 = ImVec4(0.00f, 0.59f, 0.90f, 1.00f);
  colors[ImGuiCol_ButtonHovered]          = ImVec4(0.00f, 0.59f, 0.90f, 0.92f);
  colors[ImGuiCol_ButtonActive]           = ImVec4(0.00f, 0.62f, 0.95f, 1.00f);
  colors[ImGuiCol_Header]                 = ImVec4(0.00f, 0.59f, 0.90f, 1.00f);
  colors[ImGuiCol_HeaderHovered]          = ImVec4(0.00f, 0.59f, 0.90f, 0.92f);
  colors[ImGuiCol_HeaderActive]           = ImVec4(0.00f, 0.62f, 0.95f, 1.00f);
  colors[ImGuiCol_Separator]              = ImVec4(0.43f, 0.43f, 0.50f, 0.50f);
  colors[ImGuiCol_SeparatorHovered]       = ImVec4(0.10f, 0.40f, 0.75f, 0.78f);
  colors[ImGuiCol_SeparatorActive]        = ImVec4(0.10f, 0.40f, 0.75f, 1.00f);
  colors[ImGuiCol_ResizeGrip]             = ImVec4(0.26f, 0.59f, 0.98f, 0.20f);
  colors[ImGuiCol_ResizeGripHovered]      = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
  colors[ImGuiCol_ResizeGripActive]       = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
  colors[ImGuiCol_Tab]                    = ImVec4(0.00f, 0.59f, 0.90f, 1.00f);
  colors[ImGuiCol_TabHovered]             = ImVec4(0.00f, 0.59f, 0.90f, 0.92f);
  colors[ImGuiCol_TabActive]              = ImVec4(0.00f, 0.62f, 0.95f, 1.00f);
  colors[ImGuiCol_TabUnfocusedActive]     = ImVec4(0.00f, 0.59f, 0.90f, 0.66f);
  colors[ImGuiCol_DockingPreview]         = ImVec4(0.26f, 0.59f, 0.98f, 0.70f);
  colors[ImGuiCol_DockingEmptyBg]         = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);
  colors[ImGuiCol_PlotLines]              = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
  colors[ImGuiCol_PlotLinesHovered]       = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
  colors[ImGuiCol_PlotHistogram]          = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
  colors[ImGuiCol_PlotHistogramHovered]   = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
  colors[ImGuiCol_TableHeaderBg]          = ImVec4(0.19f, 0.19f, 0.20f, 1.00f);
  colors[ImGuiCol_TableBorderStrong]      = ImVec4(0.31f, 0.31f, 0.35f, 1.00f);
  colors[ImGuiCol_TableBorderLight]       = ImVec4(0.23f, 0.23f, 0.25f, 1.00f);
  colors[ImGuiCol_TableRowBg]             = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
  colors[ImGuiCol_TableRowBgAlt]          = ImVec4(1.00f, 1.00f, 1.00f, 0.06f);
  colors[ImGuiCol_TextSelectedBg]         = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
  colors[ImGuiCol_DragDropTarget]         = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
  colors[ImGuiCol_NavHighlight]           = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
  colors[ImGuiCol_NavWindowingHighlight]  = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
  colors[ImGuiCol_NavWindowingDimBg]      = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
  colors[ImGuiCol_ModalWindowDimBg]       = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);

  /* Window & Widget Style */
  ImGuiStyle& style = ImGui::GetStyle();
  style.WindowPadding = ImVec2(8.0f, 8.0f);
  style.FramePadding = ImVec2(8.0f, 4.0f);
  style.CellPadding = ImVec2(8.0f, 4.0f);
  style.ItemSpacing = ImVec2(8.0f, 8.0f);
  style.ItemInnerSpacing = ImVec2(8.0f, 8.0f);
  style.IndentSpacing = 8.0f;
  style.ScrollbarSize = 12.0f;
  style.GrabMinSize = 12.0f;
  style.TabRounding = 8.0f;
  style.WindowRounding = 8.0f;
  style.FrameRounding = 4.0f;
  style.ChildRounding = 0.0f;
  style.PopupRounding = 8.0f;
  style.ScrollbarRounding = 8.0f;
  style.GrabRounding = 8.0f;
}

void BaseWindow::addComponent(Object* obj) {
  std::string type = obj->getType(); 
  std::string id   = "##" + type + "_";

  if (this->m_componentIds.find(type) != this->m_componentIds.end()) {
    id += "0";
    this->m_componentIds[type].pushBack(id);
  } else {
    id += std::to_string(this->m_componentIds[type].getSize() + 1);
    this->m_componentIds[type].pushBack(id);
  }

  obj->setId(id);

  /* push to layout */
  if (this->m_layout == nullptr) {
    this->m_layout = new Layout();  
  }

  this->m_layout->addComponent(obj);
}

void BaseWindow::setEnableDockspace(bool value) {
  this->m_dockspaceEnabled = value;
}

void BaseWindow::setLayout(Layout* layout) { 
  this->m_layout = layout;
}