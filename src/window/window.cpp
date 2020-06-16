#include "window.hpp"
#include <filesystem>
#include <spdlog/spdlog.h>
#include <string>

Window::Window() {
  SPDLOG_INFO("constructing the window");

  m_window.create(sf::VideoMode(800, 600), "SUPREME-OCTO-RPG");
  m_window.setFramerateLimit(60);

  if (!(m_font.loadFromFile("resources/fonts/SourceCodePro-Regular.ttf") ||
        m_font.loadFromFile("../../../resources/fonts/SourceCodePro-Regular.ttf"))) {
    SPDLOG_CRITICAL("!m_font.loadFromFile()");
  }

  SPDLOG_INFO("window constructed nicely, all resources loaded");
  SPDLOG_INFO("current path: " + std::filesystem::current_path().string());
}

Window::~Window() {}
