
#include "stack_machine.hpp"
#include "states/state_game.hpp"
#include "utils.hpp"

RenderStuffs StateGame::GiveRenderStuffs() {
  RenderStuffs render_stuffs;

  {
    LayerAndTexture lat{ 1, "" };

    Quad quad({ 100.f, 100.f }, { 140.f, 140.f });
    quad.SetColor(sf::Color::Yellow);

    render_stuffs.quads[lat].push_back(quad);
  }

  {
    Text text;
    text.pos = sf::Vector2f(10.0f, 10.0f);
    text.str = "game";
    render_stuffs.texts.push_back(text);
  }

  return render_stuffs;
}