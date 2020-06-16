#pragma once

#include "../game_state.hpp"

class StateBoot : public BaseGameState {
private:
  bool done = false;

public:
  StateBoot();
  ~StateBoot();

  virtual void GetEvents(const std::vector<sf::Event>& _events);

  virtual void Compute(StackMachine& _stack_machine);

  virtual RenderStuffs GiveRenderStuffs();
};