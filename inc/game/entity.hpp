#pragma once

#include <SFML/Graphics.hpp>

class Entity {
public:
  enum class Type {
    Player,
  };

  sf::Vector2f m_position;
  sf::Vector2f m_velocity; 
  sf::Vector2f m_acceleration; 

  std::string m_texture_name;
  sf::Vector2i m_texture_position;
  sf::Vector2i m_texture_size;

  Type m_type;

  static constexpr float maxSpeed = 5.0f; 
  static constexpr float accelerationRate = 12.5f; 
  static constexpr float decelerationRate = 12.5f; 

public:
  Entity() :
    m_velocity(sf::Vector2f(0.f, 0.f)),
    m_acceleration(sf::Vector2f(0.f, 0.f))
  {}


  void update(sf::Time deltaTime) {

    m_velocity += m_acceleration * deltaTime.asSeconds();

    float currentSpeed = std::sqrt(m_velocity.x * m_velocity.x + m_velocity.y * m_velocity.y);
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
};

