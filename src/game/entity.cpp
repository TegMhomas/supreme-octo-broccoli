#include "game/entity.hpp"

Entity::Entity(Type type, int hp, int sp, int defense, int attack, float movementSpeedModifier): m_type(type), m_hp(hp), m_sp(sp), m_defense(defense), m_attack(attack), m_movement_speed(movementSpeedModifier), m_velocity(sf::Vector2f(0.f, 0.f)), m_acceleration(sf::Vector2f(0.f, 0.f)) {}

Entity::~Entity() {}

void Entity::update(sf::Time deltaTime) {
  m_velocity += m_acceleration * deltaTime.asSeconds();

  float maxAdjustedSpeed = baseSpeed * m_movement_speed;
  float currentSpeed = std::hypot(m_velocity.x, m_velocity.y); 
  if (currentSpeed > maxAdjustedSpeed) {
    m_velocity = maxAdjustedSpeed / currentSpeed * m_velocity;
  }

  if (m_acceleration.x == 0.f && m_velocity.x != 0.f) {
    m_velocity.x += -decelerationRate * deltaTime.asSeconds() * (m_velocity.x > 0.f ? 1.f : -1.f);
    if (std::abs(m_velocity.x) < decelerationRate * deltaTime.asSeconds()) {
      m_velocity.x = 0.f;
    }
  }
  if (m_acceleration.y == 0.f && m_velocity.y != 0.f) {
    m_velocity.y += -decelerationRate * deltaTime.asSeconds() * (m_velocity.y > 0.f ? 1.f : -1.f);
    if (std::abs(m_velocity.y) < decelerationRate * deltaTime.asSeconds()) {
      m_velocity.y = 0.f;
    }
  }

  m_position += m_velocity * deltaTime.asSeconds();

  m_acceleration = sf::Vector2f(0.f, 0.f);
}


void Entity::takeDamage(int amount) {
  int damageTaken = std::max(amount - m_defense, 0);
  m_hp -= damageTaken;
  m_hp = std::clamp(m_hp, 0, m_hp);
}

void Entity::heal(int amount) {
  m_hp += amount;
  m_hp = std::clamp(m_hp, 0, 100); 
}

void Entity::useStamina(int amount) {
  m_sp -= amount;
  m_sp = std::clamp(m_sp, 0, m_sp);
}

void Entity::recoverStamina(int amount) {
  m_sp += amount;
  m_sp = std::clamp(m_sp, 0, 100); 
}

void Entity::setTextureName(const std::string& name) {
  m_texture_name = name;
}

void Entity::setTexturePosition(const sf::Vector2i& position) {
  m_texture_position = position;
}

void Entity::setTextureSize(const sf::Vector2i& size) {
  m_texture_size = size;
}

const sf::Vector2f& Entity::getPosition() const {
  return m_position;
}

const sf::Vector2f& Entity::getVelocity() const {
  return m_velocity;
}

const std::string& Entity::getTextureName() const {
  return m_texture_name;
}

const sf::Vector2i& Entity::getTexturePosition() const {
  return m_texture_position;
}

const sf::Vector2i& Entity::getTextureSize() const {
  return m_texture_size;
}

Entity::Type Entity::getType() const {
  return m_type;
}

void Entity::setAcceleration(const sf::Vector2f& acc) {
  m_acceleration = acc;
}

sf::Vector2f Entity::getAcceleration() const {
  return m_acceleration;
}