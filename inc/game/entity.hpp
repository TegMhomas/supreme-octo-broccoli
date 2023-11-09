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

  Entity();

  void update(sf::Time deltaTime);
};

