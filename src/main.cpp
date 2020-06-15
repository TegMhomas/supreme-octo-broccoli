#include <SFML/Graphics.hpp>

#include "stack_machine.hpp"
#include "window.hpp"
#include "states/state_boot.hpp"

int main() {

  StackMachine machine;
  Window window;

  machine.m_game_stack.push(std::make_unique<StateBoot>());

  while (!machine.m_game_stack.empty()) {
    machine.m_game_stack.top()->GetEvents(window.GiveEvents());
    machine.m_game_stack.top()->Compute(machine);
    window.GetRenderStuffs(machine.m_game_stack.top()->GiveRenderStuffs());
    window.Render();
  }

  return 0;
}