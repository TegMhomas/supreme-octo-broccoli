
#include "game/room.hpp"
#include "utils.hpp"
#include <cereal/archives/binary.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/archives/xml.hpp>
#include <cereal/cereal.hpp>
#include <cereal/types/vector.hpp>
#include <fstream>

Room::Room() {

  Tile tile;
  tile.m_texture_name = "";

  tile.m_position_in_room = { 0, 0 };
  m_tiles.push_back(tile);
  tile.m_position_in_room = { 0, 100 };
  m_tiles.push_back(tile);
  tile.m_position_in_room = { 100, 0 };
  m_tiles.push_back(tile);
  tile.m_position_in_room = { 100, 100 };
  m_tiles.push_back(tile);
}

Room::Room(const std::string _room_config_name) {
  std::ifstream is;

  std::string path_prefix = FindPathToResources();

  is.open(path_prefix + "Rooms/" + _room_config_name);

  if (!is.is_open()) {
    SPDLOG_ERROR("can't find: " + _room_config_name);
    std::terminate();
  }

  std::unique_ptr<cereal::XMLInputArchive> archive =
    std::make_unique<cereal::XMLInputArchive>(is);

  (*archive)(cereal::make_nvp("m_tiles", m_tiles));
}

Room::~Room() {}

std::vector<Tile>& Room::GetAllTiles() {
  return m_tiles;
}

Tile& Room::GetTileAt(const sf::Vector2i _position) {
  if (_position.x >= 0 && _position.y >= 0 && _position.x < m_size.x &&
      _position.y < m_size.y) {

    // todo:
    // return m_tiles[_position.x * m_size. + ];
    return m_tiles[0];

  } else {
    SPDLOG_ERROR("GetTileAt() invalid position (" +
                 std::to_string(_position.x) + ", " +
                 std::to_string(_position.y) + ")");
    return m_tiles[0];
  }
}