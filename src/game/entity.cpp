#include "game/entity.hpp"
#include "entity.hpp"

Entity::Entity(Type type)
  : m_type(type)
  , stats()
  , m_velocity(sf::Vector2f(0.f, 0.f))
  , m_acceleration(sf::Vector2f(0.f, 0.f)) {}

Entity::Entity(Type type, const EntityStats& statsValues)
  : m_type(type)
  , stats(statsValues)
  , m_velocity(sf::Vector2f(0.f, 0.f))
  , m_acceleration(sf::Vector2f(0.f, 0.f)) {}

Entity::~Entity() {}

void Entity::update(sf::Time deltaTime) {
  m_velocity += m_acceleration * deltaTime.asSeconds();

  float maxAdjustedSpeed = baseSpeed * stats.getStat(EntityStats::MovementSpeed);
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

void Entity::takeDamage(float amount) {
  int damageTaken = std::max(amount - stats.getStat(EntityStats::Defense), 0.0f);
  stats.modifyStat(EntityStats::HP, -damageTaken);
}

void Entity::heal(float amount) {
  stats.modifyStat(EntityStats::HP, amount);
}

void Entity::useStamina(float amount) {
  stats.modifyStat(EntityStats::SP, -amount);
}

void Entity::recoverStamina(float amount) {
  stats.modifyStat(EntityStats::SP, amount);
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

void Entity::registerInPhysicsEngine() {}