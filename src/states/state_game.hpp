#pragma once

#include "game/room.hpp"
#include "game_state.hpp"
#include <vector>
#include "game/entity.hpp"
#include "game/player.hpp"
#include "game/physics.hpp"

class StateGame : public BaseGameState {
private:
  bool m_done = false;
  Room m_current_room;
  std::vector<std::shared_ptr<Entity>> m_entities;
  sf::Clock m_frame_clock;
  std::map<sf::Keyboard::Key, bool> m_key_map;
  Physics m_physics;

public:
  StateGame();
  ~StateGame();

  virtual void GetEvents(const std::vector<sf::Event>& _events);

  virtual void Compute(StackMachine& _stack_machine);

  virtual RenderStuffs GiveRenderStuffs();
};