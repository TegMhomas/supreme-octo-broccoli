#pragma once

#include <SFML/Graphics.hpp>
#include <cereal/cereal.hpp>
#include <string>

class Tile {
public:
  sf::Vector2i m_position_in_room;
  sf::Vector2i m_texture_position;
  std::string m_texture_name;

  bool m_walkable = true;

  template<class Archive>
  void serialize(Archive& archive) {
    archive(cereal::make_nvp("m_position_in_room.x", m_position_in_room.x),
            cereal::make_nvp("m_position_in_room.y", m_position_in_room.y),
            cereal::make_nvp("m_texture_position.x", m_texture_position.x),
            cereal::make_nvp("m_texture_position.y", m_texture_position.y),
            cereal::make_nvp("m_texture_name", m_texture_name),
            cereal::make_nvp("m_walkable", m_walkable));
  }
};