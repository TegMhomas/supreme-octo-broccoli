

#include <SFML/Graphics.hpp>
#include "game/entity.hpp"
#include <box2d/box2d.h>

/// @brief Represents the whole physics world, and holds box2d things.
class Physics {
public:
  Physics();
  ~Physics();

  Physics(const Physics& other) = delete;
  Physics(Physics&& other) noexcept = delete;

  Physics& operator=(const Physics& other) = delete;
  Physics& operator=(Physics&& other) noexcept = delete;

  /// @brief Simulate one tick of physics world simulation.
  /// Internally makes sure to simulate physics if enough time passed since last simulation. (TODO)
  void simulateOneTick();

  /// @brief Handle an entity in the physics world.
  /// Apply forces if needed, update the position and other vars of the entity, etc.
  /// Register an entity in physics world and give it a physics body, if it needs one.
  void updateEntity(Entity& entity);

private:
  /// @brief Physics world.
  b2World m_b2_world;
  /// @brief Static physics body, used to anchor entity bodies to it, so they get top-down friction.
  b2Body* m_static_body = nullptr;
};
