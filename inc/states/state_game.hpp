#pragma once

#include "../game/room.hpp"
#include "../game_state.hpp"
#include <vector>
#include "../game/entity.hpp"

class StateGame : public BaseGameState {
private:
  bool m_done = false;
  Room m_current_room;
  std::vector<Entity> m_entities;
  sf::Clock frameClock;

public:
  StateGame();
  ~StateGame();

  virtual void GetEvents(const std::vector<sf::Event>& _events);

  virtual void Compute(StackMachine& _stack_machine);

  virtual RenderStuffs GiveRenderStuffs();
};