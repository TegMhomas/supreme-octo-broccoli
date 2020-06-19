
#include "stack_machine.hpp"
#include "states/state_game.hpp"
#include "utils.hpp"

void StateGame::GetEvents(const std::vector<sf::Event>& _events) {
  for (const auto& event : _events) {
    if (event.type == sf::Event::Closed) {
      done = true;
    }
  }
}
