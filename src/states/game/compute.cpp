
#include "stack_machine.hpp"
#include "states/state_game.hpp"
#include "utils.hpp"

void StateGame::Compute(StackMachine& _stack_machine) {
  if (m_done == true) {
    _stack_machine.m_game_stack.pop();
  }
}
