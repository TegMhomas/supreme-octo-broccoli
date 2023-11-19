
#include "stack_machine.hpp"
#include "states/state_game.hpp"
#include "utils.hpp"

void StateGame::Compute(StackMachine& _stack_machine) {
  if (m_done) {
    _stack_machine.m_game_stack.pop();
    return;
  }

  sf::Time deltaTime = m_frame_clock.restart();

  for (auto& entityPtr : m_entities) {
    Entity& entity = *entityPtr;

    if (entity.getType() == Entity::Type::Player) {

      sf::Vector2f acceleration(0.f, 0.f);

      if (m_key_map[sf::Keyboard::Up]) {
        acceleration.y -= Entity::accelerationRate;
      }
      if (m_key_map[sf::Keyboard::Down]) {
        acceleration.y += Entity::accelerationRate;
      }
      if (m_key_map[sf::Keyboard::Left]) {
        acceleration.x -= Entity::accelerationRate;
      }
      if (m_key_map[sf::Keyboard::Right]) {
        acceleration.x += Entity::accelerationRate;
      }

      entity.setAcceleration(acceleration);
      // entity.update(deltaTime);
    }

    if (entity.getType() == Entity::Type::Enemy) {
    }
  }

  m_physics.simulateOneTick();

  for (auto& entity : m_entities) {
    m_physics.updateEntity(*entity);
  }
}
