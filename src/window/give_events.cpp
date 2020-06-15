#include "window.hpp"

std::vector<sf::Event> Window::GiveEvents() {
  std::vector<sf::Event> events;

  sf::Event event;
  while (m_window.pollEvent(event)) {
    events.push_back(event);
  }

  return events;
}