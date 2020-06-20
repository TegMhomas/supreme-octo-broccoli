
#include "stack_machine.hpp"
#include "states/state_boot.hpp"
#include "states/state_game.hpp"
#include "utils.hpp"
#include "window.hpp"
#include <SFML/Graphics.hpp>

int main() {
  spdlog::set_level(spdlog::level::debug);
  spdlog::set_pattern("[%H:%M:%S:%e] [%^%=8l%$] [%17s:%-3#] -- %v");

  SPDLOG_INFO("main()");

  StackMachine machine;
  Window window;

  SPDLOG_INFO("pushing to stack");

  machine.m_game_stack.push(std::make_unique<StateGame>());
  machine.m_game_stack.push(std::make_unique<StateBoot>());

  SPDLOG_INFO("starting the game loop");

  while (!machine.m_game_stack.empty()) {
    window.Render(machine.m_game_stack.top()->GiveRenderStuffs());
    machine.m_game_stack.top()->GetEvents(window.GiveEvents());
    machine.m_game_stack.top()->Compute(machine);
  }

  SPDLOG_TRACE("returning from main()");

  return 0;
}