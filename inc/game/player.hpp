#pragma once

#include "entity.hpp"

class Player : public Entity {
public:
  // std::vector<Item> m_inventory;

  Player(int hp, int sp, int defense, int attack, float movementSpeed);


  void update(sf::Time deltaTime) override;

};