#pragma once

#include "entity.hpp"

class Player : public Entity {
public:
  // std::vector<Item> m_inventory;

 Player(const EntityStats& stats);
 Player();


  void update(sf::Time deltaTime) override;

};