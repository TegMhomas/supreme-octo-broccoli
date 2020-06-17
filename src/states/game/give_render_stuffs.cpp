
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
                  { 100.f, 100.f });

      quad.SetColor(sf::Color::Red);

      render_stuffs.quads[lat].push_back(quad);
    }
  }

  {
    Text text;
    text.pos = sf::Vector2f(10.0f, 10.0f);
    text.str = "game";
    render_stuffs.texts.push_back(text);
  }

  return render_stuffs;
}