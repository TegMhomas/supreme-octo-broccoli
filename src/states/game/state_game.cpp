
#include "states/state_game.hpp"
#include "stack_machine.hpp"
#include "utils.hpp"

StateGame::StateGame() {
  SPDLOG_INFO("state game constructing");
  m_current_room = Room("L0.txt");

  m_entities.push_back(Entity());
  auto& player = m_entities.back();
  player.m_texture_name = "kmiecik.png";
  player.m_texture_position = { 0, 0 };
  player.m_texture_size = { 64, 64 };
  m_key_map[sf::Keyboard::Up] = false;
  m_key_map[sf::Keyboard::Down] = false;
  m_key_map[sf::Keyboard::Left] = false;
  m_key_map[sf::Keyboard::Right] = false;
}

StateGame::~StateGame() {
  SPDLOG_INFO("state game destructing");
}
