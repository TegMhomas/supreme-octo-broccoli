#pragma once

#include <stack>
#include <memory>
#include "game_state.hpp"

class StackMachine {
public:
  std::stack<std::unique_ptr<BaseGameState>> m_game_stack;


};


