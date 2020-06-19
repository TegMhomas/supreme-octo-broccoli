
#include "states/state_game.hpp"
#include "stack_machine.hpp"
#include "utils.hpp"

StateGame::StateGame() {
  SPDLOG_INFO("state game constructing");
  m_current_room = Room("L0.txt");
}

StateGame::~StateGame() {
  SPDLOG_INFO("state game destructing");
}
