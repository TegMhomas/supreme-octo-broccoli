#pragma once

#include <SFML/Graphics.hpp>

class Entity {
public:
  enum class Type {
    Player,
  };

public:
  sf::Vector2f m_position;

  std::string m_texture_name;
  sf::Vector2i m_texture_position;
  sf::Vector2i m_texture_size;

  Type m_type;

public:
  Entity() {}
};