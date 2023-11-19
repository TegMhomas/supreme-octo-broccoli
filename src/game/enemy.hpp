#pragma once

#include "Entity.hpp"

class Enemy : public Entity {
public:
  Enemy(const sf::Vector2f& position, const EntityStats& stats, const std::string& textureName);

  void update(sf::Time deltaTime, const sf::Vector2f& playerPosition) override;
};