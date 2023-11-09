
#include "stack_machine.hpp"
#include "states/state_game.hpp"
#include "utils.hpp"
#include <optional>

void StateGame::GetEvents(const std::vector<sf::Event>& _events) {
  for (const auto& event : _events) {
    if (event.type == sf::Event::Closed) {
      m_done = true;
    } else if (event.type == sf::Event::KeyPressed) {
      m_key_map[event.key.code] = true;
    } else if (event.type == sf::Event::KeyReleased) {
      m_key_map[event.key.code] = false;
    }
  }
}
