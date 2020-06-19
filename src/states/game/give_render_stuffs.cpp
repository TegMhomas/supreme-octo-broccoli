
#include "stack_machine.hpp"
#include "states/state_game.hpp"
#include "utils.hpp"

RenderStuffs StateGame::GiveRenderStuffs() {
  RenderStuffs render_stuffs;

  {
    LayerAndTexture lat{ 1, "" };
    Quad quad;

    const auto& tiles = m_current_room.GetAllTiles();

    SPDLOG_DEBUG("aaa");
    for (const auto& tile : tiles) {
      quad = Quad({ static_cast<sf::Vector2f>(tile.m_position_in_room) },
                  { 100.f, 100.f });

      lat.texture = tile.m_texture_name;
      SPDLOG_DEBUG(lat.texture);

      if (render_stuffs.quads.contains(lat)) {
        render_stuffs.quads[lat].push_back(quad);
        SPDLOG_DEBUG("contains");
      } else {
        render_stuffs.quads[lat] = std::vector<Quad>();
        render_stuffs.quads[lat].push_back(quad);
        SPDLOG_DEBUG("not contains");
      }
    }
  }

  {
    Text text;
    text.pos = sf::Vector2f(10.0f, 10.0f);
   // text.str = "game";
    render_stuffs.texts.push_back(text);
  }

  return render_stuffs;
}