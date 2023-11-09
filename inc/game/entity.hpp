#pragma once

#include <SFML/Graphics.hpp>
#include "entity_stats.hpp"

class Entity {
public:
  enum class Type {
    Player,
    Enemy,
  };

  sf::Vector2f m_position;
  sf::Vector2f m_velocity;
  sf::Vector2f m_acceleration;
  std::string m_texture_name;
  sf::Vector2i m_texture_position;
  sf::Vector2i m_texture_size;

  Type m_type;

  EntityStats stats;

  static constexpr float baseSpeed = 5.0f;
  static constexpr float accelerationRate = 12.5f;
  static constexpr float decelerationRate = 12.5f;


  Entity(Type type);
  Entity(Type type, const EntityStats &stats);

  virtual ~Entity();

  virtual void update(sf::Time deltaTime);

  void takeDamage(float amount);
  void heal(float amount);
  void useStamina(float amount);
  void recoverStamina(float amount);

  void setTextureName(const std::string& name);
  void setTexturePosition(const sf::Vector2i& position);
  void setTextureSize(const sf::Vector2i& size);

  const sf::Vector2f& getPosition() const;
  const sf::Vector2f& getVelocity() const;
  const std::string& getTextureName() const;
  const sf::Vector2i& getTexturePosition() const;
  const sf::Vector2i& getTextureSize() const;

  Type getType() const;

  void setAcceleration(const sf::Vector2f& acc);

  sf::Vector2f getAcceleration() const;
};

