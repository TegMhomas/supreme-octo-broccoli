#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

//using Quad = std::array<sf::Vector2f, 4>;

struct Text {
  sf::Vector2f pos;
  std::string str;
};

struct RenderStuffs {
  //std::vector<std::vector<Quad>> quads; // czworok¹ty
  std::vector<Text> texts; // texty
  std::vector<std::string> texts_for_textbox;

};