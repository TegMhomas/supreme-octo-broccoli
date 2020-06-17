#pragma once

#include "tile.hpp"
#include <vector>

class Room {
private:
  sf::Vector2i m_size;
  std::vector<Tile> m_tiles;

public:
  Room();
  Room(const std::string _config_name);
  ~Room();

  Room(const Room& other) = delete;
  Room(Room&& other) noexcept = default;

  Room& operator=(const Room& other) = delete;
  Room& operator=(Room&& other) noexcept = default;

public:
  std::vector<Tile>& GetAllTiles();

  Tile& GetTileAt(const sf::Vector2i _position);
};