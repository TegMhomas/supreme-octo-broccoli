

#include <SFML/Graphics.hpp>
#include "game/entity.hpp"

/// @brief Represents the whole physics world, and holds box2d things.
class Physics {
public:
  Physics();
  ~Physics();

  Physics(const Physics& other) = delete;
  Physics(Physics&& other) noexcept = delete;

  Physics& operator=(const Physics& other) = delete;
  Physics& operator=(Physics&& other) noexcept = delete;

private:
};