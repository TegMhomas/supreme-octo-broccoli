#include "game/player.hpp"

Player::Player(const EntityStats& stats) : Entity(Type::Player, stats) {}
Player::Player() : Entity(Type::Player) {}

void Player::update(sf::Time deltaTime) {

  Entity::update(deltaTime);

  //recoverStamina(1);
  //heal(1);
}