
#include "states/state_boot.hpp"
#include "stack_machine.hpp"
#include "utils.hpp"

StateBoot::StateBoot() {
  SPDLOG_INFO("state boot constructing");
}

StateBoot::~StateBoot() {
  SPDLOG_INFO("state boot destructing");
}

void StateBoot::GetEvents(const std::vector<sf::Event>& _events) {
  for (const auto& event : _events) {
    if (event.type == sf::Event::Closed) {
      m_done = true;
    } else if (event.type == sf::Event::KeyPressed) {
      if (event.key.code == sf::Keyboard::Escape) {
        m_done = true;
      }
    }
  }
}

void StateBoot::Compute(StackMachine& _stack_machine) {
  if (m_done == true) {
    _stack_machine.m_game_stack.pop();
  }
}

RenderStuffs StateBoot::GiveRenderStuffs() {
  RenderStuffs render_stuffs;

  {
    LayerAndTexture lat{ 1, "" };

    Quad quad({ 100.f, 100.f }, { 140.f, 140.f });
    quad.SetColor(sf::Color::Yellow);

    render_stuffs.quads[lat].push_back(quad);
  }

  {
    Text text;
    text.pos = sf::Vector2f(10.0f, 10.0f);
    text.str = "Press Escape To START!";
    render_stuffs.texts.push_back(text);
  }

  return render_stuffs;
}