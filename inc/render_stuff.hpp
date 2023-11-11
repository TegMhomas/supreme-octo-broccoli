#pragma once

#include <SFML/Graphics.hpp>
#include <array>
#include <vector>

struct Quad {
  std::array<sf::Vertex, 4> arr;

  Quad() {}

  Quad(sf::Vector2f _world_xy,
       sf::Vector2f _world_wh,
       sf::Vector2f _tex_xy,
       sf::Vector2f _tex_wh) {
    arr[0].position = _world_xy;
    arr[1].position = _world_xy + sf::Vector2f{ _world_wh.x, 0.0 };
    arr[2].position = _world_xy + _world_wh;
    arr[3].position = _world_xy + sf::Vector2f{ 0.0, _world_wh.y };

    arr[0].texCoords = _tex_xy;
    arr[1].texCoords = _tex_xy + sf::Vector2f{ _tex_wh.x, 0.0 };
    arr[2].texCoords = _tex_xy + _tex_wh;
    arr[3].texCoords = _tex_xy + sf::Vector2f{ 0.0, _tex_wh.y };
  }

  void SetColor(const sf::Color& _color) {
    for (auto& v : arr)
      v.color = _color;
  }
};

struct LayerAndTexture {
  int32_t layer;
  std::string texture;
};

bool operator<(const LayerAndTexture& left, const LayerAndTexture& right);
bool operator==(const LayerAndTexture& left, const LayerAndTexture& right);

struct Text {
  sf::Vector2f pos;
  std::string str;
};

struct RenderStuffs {
  // [[warstwa, textura], czworokąt]
  std::map<LayerAndTexture, std::vector<Quad>> quads;

  std::vector<Text> texts;

  std::vector<std::string> texts_for_textbox;

  sf::View view;
};
