
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
      quad = Quad(static_cast<sf::Vector2f>(entity->getPosition()) -
                    sf::Vector2f(-0.5f, -0.5f),
                  { 1.f, 1.f });

      lat.texture = entity->getTextureName();
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

   auto& player =
    *std::find_if(m_entities.begin(), m_entities.end(), [](const auto& ent) {
      return ent->getType() == Entity::Type::Player;
    });

  // Create Text objects and add them to the render_stuffs
  render_stuffs.texts.push_back(Text{
    sf::Vector2f(10.0f, 10.0f), "HP: " + std::to_string(player->getHp()) });
  render_stuffs.texts.push_back(Text{
    sf::Vector2f(10.0f, 30.0f), "SP: " + std::to_string(player->getSp()) });
  render_stuffs.texts.push_back(
    Text{ sf::Vector2f(10.0f, 50.0f),
          "DEF: " + std::to_string(player->getDefense()) });
  render_stuffs.texts.push_back(
    Text{ sf::Vector2f(10.0f, 70.0f),
          "ATK: " + std::to_string(player->getAttack()) });


  render_stuffs.view.setSize(10.f, 10.f);
  render_stuffs.view.setCenter(5.f, 5.f);

  return render_stuffs;
}