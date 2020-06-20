
#include "stack_machine.hpp"
#include "states/state_game.hpp"
#include "utils.hpp"

RenderStuffs StateGame::GiveRenderStuffs() {
  RenderStuffs render_stuffs;

  {
    LayerAndTexture lat{ 1, "" };
    Quad quad;

    const auto& tiles = m_current_room.GetAllTiles();

    for (const auto& tile : tiles) {
      quad = Quad({ static_cast<sf::Vector2f>(tile.m_position_in_room) },
                  { 1.f, 1.f });

      lat.texture = tile.m_texture_name;
      lat.layer = tile.m_layer;

      if (render_stuffs.quads.contains(lat)) {
        render_stuffs.quads[lat].push_back(quad);
      } else {
        render_stuffs.quads[lat] = std::vector<Quad>();
        render_stuffs.quads[lat].push_back(quad);
      }
    }
  }

  {
    LayerAndTexture lat{ 1, "" };
    Quad quad;

    for (const auto& entity : m_entities) {
      quad = Quad(static_cast<sf::Vector2f>(entity.m_position) -
                    sf::Vector2f(-0.5f, -0.5f),
                  { 1.f, 1.f });

      lat.texture = entity.m_texture_name;
      lat.layer = 5;

      if (render_stuffs.quads.contains(lat)) {
        render_stuffs.quads[lat].push_back(quad);
      } else {
        render_stuffs.quads[lat] = std::vector<Quad>();
        render_stuffs.quads[lat].push_back(quad);
      }
    }
  }

  {
    Text text;
    text.pos = sf::Vector2f(10.0f, 10.0f);
    // text.str = "game";
    render_stuffs.texts.push_back(text);
  }

  render_stuffs.view.setSize(10.f, 10.f);
  render_stuffs.view.setCenter(3.f, 3.f);

  return render_stuffs;
}