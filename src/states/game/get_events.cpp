
#include "stack_machine.hpp"
#include "states/state_game.hpp"
#include "utils.hpp"
#include <optional>

void StateGame::GetEvents(const std::vector<sf::Event>& _events) {
  for (const auto& event : _events) {
    if (event.type == sf::Event::Closed) {
      m_done = true;
    } else if (event.type == sf::Event::KeyPressed) {
      switch (event.key.code) {
        case sf::Keyboard::Up:
          m_key_map[sf::Keyboard::Up] = true;
          break;
        case sf::Keyboard::Down:
          m_key_map[sf::Keyboard::Down] = true;
          break;
        case sf::Keyboard::Left:
          m_key_map[sf::Keyboard::Left] = true;
          break;
        case sf::Keyboard::Right:
          m_key_map[sf::Keyboard::Right] = true;
          break;
        default:
          break; 
      }
    } else if (event.type == sf::Event::KeyReleased) {
      switch (event.key.code) {
        case sf::Keyboard::Up:
          m_key_map[sf::Keyboard::Up] = false;
          break;
        case sf::Keyboard::Down:
          m_key_map[sf::Keyboard::Down] = false;
          break;
        case sf::Keyboard::Left:
          m_key_map[sf::Keyboard::Left] = false;
          break;
        case sf::Keyboard::Right:
          m_key_map[sf::Keyboard::Right] = false;
          break;
        default:
          break; 
      }
    }
  }
}
