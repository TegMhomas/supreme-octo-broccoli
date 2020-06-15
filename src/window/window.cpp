#include "window.hpp"

Window::Window() {
  m_window.create(sf::VideoMode(200, 200), "HELLO WORLD!");

}

Window::~Window() {

}
