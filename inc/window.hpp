#pragma once

#include "render_stuff.hpp"
#include <SFML/Graphics.hpp>

class Window {
private:
  sf::RenderWindow m_window;
 
public:
  Window();
  ~Window();

  Window(const Window& other) = delete;
  Window(Window&& other) noexcept = delete;

  Window& operator=(const Window& other) = delete;
  Window& operator=(Window&& other) noexcept = delete;

public:
  void GetRenderStuffs(RenderStuffs& _render_stuffs);

  void Render();
  

  std::vector<sf::Event> GiveEvents();

private:
  // todo: wczytaj opcje
};
