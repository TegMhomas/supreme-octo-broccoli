
#pragma once

#include "../game_state.hpp"

class StateBoot : public BaseGameState {
public:
  virtual void GetEvents(std::vector<sf::Event> _events) {}

  virtual void Compute(StackMachine& _stack_machine) {}

  virtual RenderStuffs GiveRenderStuffs() {
    RenderStuffs render_stuffs;
    return render_stuffs;
  }
};