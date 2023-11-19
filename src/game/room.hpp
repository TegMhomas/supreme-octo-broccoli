#pragma once

#include "tile.hpp"
#include <vector>

class Room {
private:
  /// @brief Room size. Max x and y of its tiles.
  sf::Vector2i m_size;

  /// @brief
  std::vector<Tile> m_tiles;

public:
  Room();
  ~Room();

  Room(const Room& other) = delete;
  Room(Room&& other) noexcept = default;

  Room& operator=(const Room& other) = delete;
  Room& operator=(Room&& other) noexcept = default;

  /// @brief Loads room from file in Tiled tmj format.
  /// @param room Filename of room, from inside the `resources\Rooms` dir.
  /// @return Loaded room, or empty room if error.
  static Room loadFromTmj(const std::string& room_filename);

  sf::Vector2i getRoomSize();

  std::vector<Tile>& GetAllTiles();

  Tile& GetTileAt(const sf::Vector2i _position);
};