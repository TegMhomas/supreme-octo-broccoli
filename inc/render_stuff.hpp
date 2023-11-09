#pragma once

#include <SFML/Graphics.hpp>
#include <array>
#include <vector>

struct Quad {
  std::array<sf::Vertex, 4> arr;

  Quad() {}

  Quad(sf::Vector2f _xy, sf::Vector2f _wh) {
    arr[0].position = _xy;
    arr[1].position = { _xy.x + _wh.x, _xy.y };
    arr[2].position = _xy + _wh;
    arr[3].position = { _xy.x, _xy.y + _wh.y };

    arr[0].texCoords = { 0.f, 0.f };
    arr[1].texCoords = { 64.f, 0.f };
    arr[2].texCoords = { 64.f, 64.f };
    arr[3].texCoords = { 0.f, 64.f };
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
