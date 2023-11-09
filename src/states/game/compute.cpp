
#include "stack_machine.hpp"
#include "states/state_game.hpp"
#include "utils.hpp"

void StateGame::Compute(StackMachine& _stack_machine) {
  if (m_done) {
    _stack_machine.m_game_stack.pop();
    return;
  }

  sf::Time deltaTime = m_frame_clock.restart();


  for (auto& entity : m_entities) {
    if (entity.m_type == Entity::Type::Player) {

      entity.m_acceleration = sf::Vector2f(0.f, 0.f);

      if (m_key_map[sf::Keyboard::Up]) {
        entity.m_acceleration.y -= Entity::accelerationRate;
      }
      if (m_key_map[sf::Keyboard::Down]) {
        entity.m_acceleration.y += Entity::accelerationRate;
      }
      if (m_key_map[sf::Keyboard::Left]) {
        entity.m_acceleration.x -= Entity::accelerationRate;
      }
      if (m_key_map[sf::Keyboard::Right]) {
        entity.m_acceleration.x += Entity::accelerationRate;
      }

      entity.update(deltaTime);
    }
  }


}
