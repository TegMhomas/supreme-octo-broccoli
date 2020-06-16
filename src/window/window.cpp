#include "window.hpp"

Window::Window() {
  m_window.create(sf::VideoMode(800, 600), "SUPREME-OCTO-RPG");
  m_window.setFramerateLimit(60);
}

Window::~Window() {

}
