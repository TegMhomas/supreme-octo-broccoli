#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Tile {
public:
  sf::Vector2i m_position_in_room;
  sf::Vector2i m_texture_position;
  std::string m_texture_name;
};