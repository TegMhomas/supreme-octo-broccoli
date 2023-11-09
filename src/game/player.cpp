#include "game/player.hpp"

Player::Player(int hp, int sp, int defense, int attack, float movementSpeed)
  : Entity(Type::Player, hp, sp, defense, attack, movementSpeed) {
}

void Player::update(sf::Time deltaTime) {

  Entity::update(deltaTime);

  //recoverStamina(1);
}