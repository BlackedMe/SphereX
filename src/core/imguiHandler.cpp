#include "core/imguiHandler.hpp"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"

void ImGuiHandler::init(GLFWwindow *window)
{
  // Setup Dear ImGui context
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  io = &ImGui::GetIO();
  io->IniFilename = "../examples/assets/imgui/gui_layout.ini";
  io->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
  io->ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
  io->ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // IF using Docking Branch
  io->ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;

  // Setup Platform/Renderer backends
  ImGui_ImplGlfw_InitForOpenGL(window, true);          // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
  ImGui_ImplOpenGL3_Init();
}

void ImGuiHandler::startNewFrame()
{
  // (Your code calls glfwPollEvents())
  // ...
  // Start the Dear ImGui frame
  ImGui_ImplOpenGL3_NewFrame();
  ImGui_ImplGlfw_NewFrame();
  ImGui::NewFrame();
  ImGui::DockSpaceOverViewport();
  ImGui::ShowDemoWindow();
}

void ImGuiHandler::render()
{
  ImGui::Render();
  ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

  if(io->ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
  {
    ImGui::UpdatePlatformWindows();
    ImGui::RenderPlatformWindowsDefault();
  }
}

void ImGuiHandler::terminate()
{
  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
}
