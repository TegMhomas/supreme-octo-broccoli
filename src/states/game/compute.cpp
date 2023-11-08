
#include "stack_machine.hpp"
#include "states/state_game.hpp"
#include "utils.hpp"

void StateGame::Compute(StackMachine& _stack_machine) {
  if (m_done) {
    _stack_machine.m_game_stack.pop();
    return; 
  }

  sf::Time deltaTime = m_frame_clock.restart();

  std::optional<std::reference_wrapper<Entity>> controllable;
  for (auto& entity : m_entities) {
    if (entity.m_type == Entity::Type::Player) {
      controllable = std::ref(entity);
      break; 
    }
  }

  if (controllable) {
    Entity& entity = controllable->get();
    float moveSpeed = 5.0f; 

    if (m_key_map[sf::Keyboard::Up]) {
      entity.m_position.y -= moveSpeed * deltaTime.asSeconds();
    }
    if (m_key_map[sf::Keyboard::Down]) {
      entity.m_position.y += moveSpeed * deltaTime.asSeconds();
    }
    if (m_key_map[sf::Keyboard::Left]) {
      entity.m_position.x -= moveSpeed * deltaTime.asSeconds();
    }
    if (m_key_map[sf::Keyboard::Right]) {
      entity.m_position.x += moveSpeed * deltaTime.asSeconds();
    }
    // player collision...
  }

}
