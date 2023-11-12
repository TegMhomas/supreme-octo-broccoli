
#include "stack_machine.hpp"
#include "states/state_game.hpp"
#include "utils.hpp"
#include <iomanip>

RenderStuffs StateGame::GiveRenderStuffs() {
  RenderStuffs render_stuffs;

  {
    LayerAndTexture lat{ 1, "" };
    Quad quad;

    const auto& tiles = m_current_room.GetAllTiles();

    for (const auto& tile : tiles) {
      quad = Quad({ static_cast<sf::Vector2f>(tile.m_position_in_room) },
                  { 1.f, 1.f },
                  { static_cast<sf::Vector2f>(tile.m_texture_position) },
                  { 64.f, 64.f });

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
      quad = Quad(static_cast<sf::Vector2f>(entity->getPosition()) - sf::Vector2f(-0.5f, -0.5f),
                  { 1.f, 1.f },
                  { static_cast<sf::Vector2f>(entity->getTexturePosition()) },
                  { 64.f, 64.f });

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

  auto& player = *std::find_if(
    m_entities.begin(), m_entities.end(), [](const auto& ent) { return ent->getType() == Entity::Type::Player; });

  auto floatToString = [](float value) {
    std::stringstream stream;
    stream << std::fixed << std::setprecision(1) << value;
    return stream.str();
  };
  render_stuffs.texts.push_back(
    Text{ sf::Vector2f(10.0f, 10.0f), "HP: " + floatToString(player->stats.getStat(EntityStats::HP)) });
  render_stuffs.texts.push_back(
    Text{ sf::Vector2f(10.0f, 30.0f), "SP: " + floatToString(player->stats.getStat(EntityStats::SP)) });
  render_stuffs.texts.push_back(
    Text{ sf::Vector2f(10.0f, 50.0f), "DEF: " + floatToString(player->stats.getStat(EntityStats::Defense)) });
  render_stuffs.texts.push_back(
    Text{ sf::Vector2f(10.0f, 70.0f), "ATK: " + floatToString(player->stats.getStat(EntityStats::Attack)) });

  // view:
  {
    auto room_size = sf::Vector2f{ m_current_room.getRoomSize() };
    auto view_size = sf::Vector2f{ 20.f, 20.f };
    auto view_center =
      sf::Vector2f{ std::clamp(player->getPosition().x, 0.f + view_size.x * 0.25f, room_size.x - view_size.x * 0.25f),
                    std::clamp(player->getPosition().y, 0.f + view_size.y * 0.25f, room_size.y - view_size.y * 0.25f) };

    render_stuffs.view.setSize(view_size);
    render_stuffs.view.setCenter(view_center);
  }

  return render_stuffs;
}