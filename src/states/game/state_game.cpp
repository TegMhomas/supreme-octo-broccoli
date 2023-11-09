
#include "states/state_game.hpp"
#include "stack_machine.hpp"
#include "utils.hpp"

StateGame::StateGame() {
  SPDLOG_INFO("state game constructing");
  m_current_room = Room("L0.txt");

  auto player = std::make_unique<Player>(); 
  player->setTextureName("kmiecik.png");
  player->setTexturePosition({ 0, 0 });
  player->setTextureSize({ 64, 64 });


  m_entities.push_back(std::move(player));
  m_key_map[sf::Keyboard::Up] = false;
  m_key_map[sf::Keyboard::Down] = false;
  m_key_map[sf::Keyboard::Left] = false;
  m_key_map[sf::Keyboard::Right] = false;
}

StateGame::~StateGame() {
  SPDLOG_INFO("state game destructing");
}
