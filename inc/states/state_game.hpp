#pragma once

#include "../game/room.hpp"
#include "../game_state.hpp"

class StateGame : public BaseGameState {
private:
  bool done = false;
  Room m_current_room;

public:
  StateGame();
  ~StateGame();

  virtual void GetEvents(const std::vector<sf::Event>& _events);

  virtual void Compute(StackMachine& _stack_machine);

  virtual RenderStuffs GiveRenderStuffs();
};