#include "game/room.hpp"
#include "tileson/tileson.h"
#include "utils.hpp"
#include "game/room.hpp"

Room Room::loadFromTmj(const std::string& room_filename) {

  tson::Tileson t;
  const auto path = FindPathToResources() + "/Rooms/" + room_filename;
  std::unique_ptr<tson::Map> map = t.parse(path);
  const auto parse_status = map->getStatus();

  if (parse_status != tson::ParseStatus::OK) {
    SPDLOG_WARN("invalid room path: {}; parse status: {}", path, parse_status);
    return {};
  }

  SPDLOG_INFO("room parsed successfully: {}", room_filename);
  auto room = Room{};

  int max_x = 0;
  int max_y = 0;

  for (const auto& layer : map->getLayers()) {
    if (layer.getType() == tson::LayerType::TileLayer) {
      std::map<std::tuple<int, int>, tson::Tile*> all_tiles = layer.getTileData();
      for (const auto& [coord, tile_t] : all_tiles) {
        const auto [x, y] = coord;
        const auto rect = tile_t->getDrawingRect();

        auto tile_r = Tile{};
        tile_r.m_position_in_room = { x, y };
        tile_r.m_texture_position = { rect.x, rect.y };
        tile_r.m_texture_name = "_tileset.png";
        room.m_tiles.push_back(tile_r);

        max_x = std::max(max_x, x);
        max_y = std::max(max_y, y);
      }
    }
  }

  room.m_size = { max_x, max_y };

  return room;
}
