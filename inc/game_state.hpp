#pragma once

#include "render_stuff.hpp"
#include <SFML/Graphics.hpp>

class StackMachine;

class BaseGameState {
public:
  virtual void GetEvents(const std::vector<sf::Event>& _events) = 0;

  virtual void Compute(StackMachine& _stack_machine) = 0;

  virtual RenderStuffs GiveRenderStuffs() = 0;

  virtual ~BaseGameState(){};
};