#pragma once

#include <SFML/Graphics.hpp>

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

  int m_hp;
  int m_sp;
  int m_defense;
  int m_attack;
  float m_movement_speed = 1.0f;

  static constexpr float baseSpeed = 5.0f;
  static constexpr float accelerationRate = 12.5f;
  static constexpr float decelerationRate = 12.5f;

  Entity(Type type, int hp, int sp, int defense, int attack, float movementSpeedModifier);
  virtual ~Entity();

  virtual void update(sf::Time deltaTime);

  void takeDamage(int amount);
  void heal(int amount);
  void useStamina(int amount);
  void recoverStamina(int amount);

  void setTextureName(const std::string& name);
  void setTexturePosition(const sf::Vector2i& position);
  void setTextureSize(const sf::Vector2i& size);

  const sf::Vector2f& getPosition() const;
  const sf::Vector2f& getVelocity() const;
  const std::string& getTextureName() const;
  const sf::Vector2i& getTexturePosition() const;
  const sf::Vector2i& getTextureSize() const;

  int getHp() const { return m_hp; }
  int getSp() const { return m_sp; }
  int getDefense() const { return m_defense; }
  int getAttack() const { return m_attack; }

  Type getType() const;

  void setAcceleration(const sf::Vector2f& acc);

  sf::Vector2f getAcceleration() const;
};

