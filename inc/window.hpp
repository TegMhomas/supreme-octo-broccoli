#pragma once

#include "render_stuff.hpp"
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class Window {
private:
  sf::RenderWindow m_window;
  sf::Font m_font;
  std::map<std::string, sf::Texture> m_textures;

  sf::Clock m_fps_clock;
  float m_fps_last = 0.f;

public:
  Window();
  ~Window();

  Window(const Window& other) = delete;
  Window(Window&& other) noexcept = delete;

  Window& operator=(const Window& other) = delete;
  Window& operator=(Window&& other) noexcept = delete;

public:
  void Render(const RenderStuffs& _render_stuffs);

  std::vector<sf::Event> GiveEvents();

private:
  // todo: wczytaj opcje
};
