
#include "stack_machine.hpp"
#include "states/state_game.hpp"
#include "utils.hpp"
#include <optional>

void StateGame::GetEvents(const std::vector<sf::Event>& _events) {
  std::optional<std::reference_wrapper<Entity>> controllable;

  for (auto& entity : m_entities) {
    if (entity.m_type == Entity::Type::Player) {
      controllable = std::ref(entity);
    }
  }

  for (const auto& event : _events) {
    if (event.type == sf::Event::Closed) {
      m_done = true;
    }
    if (controllable.has_value()) {
      if (event.type == sf::Event::KeyPressed) {

        if (event.key.code == sf::Keyboard::Up) {
          controllable->get().m_position.y -= 0.1f;

        } else if (event.key.code == sf::Keyboard::Down) {
          controllable->get().m_position.y += 0.1f;

        } else if (event.key.code == sf::Keyboard::Left) {
          controllable->get().m_position.x -= 0.1f;

        } else if (event.key.code == sf::Keyboard::Right) {
          controllable->get().m_position.x += 0.1f;
        }
      }
    }
  }
}
