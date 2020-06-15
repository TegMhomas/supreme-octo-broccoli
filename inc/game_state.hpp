#pragma once

#include <SFML/Graphics.hpp>
#include "render_stuff.hpp"

class StackMachine;

class BaseGameState {
public:

  virtual void GetEvents(std::vector<sf::Event> _events) = 0;

  virtual void Compute(StackMachine& _stack_machine) = 0;

  virtual RenderStuffs GiveRenderStuffs() = 0;
};