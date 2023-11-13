
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

    if (event.type == sf::Event::KeyPressed) {
      if (event.key.code == sf::Keyboard::K) {
        auto playerIt = std::find_if(m_entities.begin(), m_entities.end(), [](const auto& ent) {return ent->getType() == Entity::Type::Player;});
        if (playerIt != m_entities.end()) {
          Player* player = dynamic_cast<Player*>(playerIt->get());
          if (player) {
            player->takeDamage(1);
          }
        }
      } else if (event.key.code == sf::Keyboard::H) {    
        auto playerIt = std::find_if(m_entities.begin(), m_entities.end(), [](const auto& ent) {return ent->getType() == Entity::Type::Player;});
        if (playerIt != m_entities.end()) {
          Player* player = dynamic_cast<Player*>(playerIt->get());
          if (player) {
            player->heal(1);
          }
        }
      }
    }
  }

}
