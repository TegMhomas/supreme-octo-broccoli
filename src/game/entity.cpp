#include "game/entity.hpp"

Entity::Entity()
  : m_velocity(sf::Vector2f(0.f, 0.f))
  , m_acceleration(sf::Vector2f(0.f, 0.f))
  , m_type(Type::Player) 
{}

void Entity::update(sf::Time deltaTime) {
  m_velocity += m_acceleration * deltaTime.asSeconds();

  float currentSpeed =
    std::hypot(m_velocity.x, m_velocity.y); 
  if (currentSpeed > maxSpeed) {
    m_velocity = maxSpeed / currentSpeed * m_velocity;
  }

  if (m_acceleration.x == 0.f && m_velocity.x != 0.f) {
    m_velocity.x += -decelerationRate * deltaTime.asSeconds() * (m_velocity.x > 0.f ? 1.f : -1.f);
    if (std::abs(m_velocity.x) < decelerationRate * deltaTime.asSeconds()) {
      m_velocity.x = 0.f;
    }
  }
  if (m_acceleration.y == 0.f && m_velocity.y != 0.f) {
    m_velocity.y += -decelerationRate * deltaTime.asSeconds() * (m_velocity.y > 0.f ? 1.f : -1.f);
    if (std::abs(m_velocity.y) < decelerationRate * deltaTime.asSeconds()) {
      m_velocity.y = 0.f;
    }
  }

  m_position += m_velocity * deltaTime.asSeconds();

  m_acceleration = sf::Vector2f(0.f, 0.f);
}