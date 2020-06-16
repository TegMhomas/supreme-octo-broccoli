#include "window.hpp"
#include <spdlog/spdlog.h>

Window::Window() {
  SPDLOG_INFO("constructing the window");

  m_window.create(sf::VideoMode(800, 600), "SUPREME-OCTO-RPG");
  m_window.setFramerateLimit(60);

  if (!m_font.loadFromFile("resources/fonts/SourceCodePro-Regular.ttf")) {
    SPDLOG_CRITICAL("!m_font.loadFromFile()");
  }

  SPDLOG_INFO("window constructed nicely, all resources loaded");
  SPDLOG_DEBUG("window constructed nicely, all resources loaded");
  SPDLOG_TRACE("window constructed nicely, all resources loaded");
}

Window::~Window() {}
