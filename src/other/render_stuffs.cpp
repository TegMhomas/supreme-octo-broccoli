#include "render_stuff.hpp"

bool operator<(const LayerAndTexture& left, const LayerAndTexture& right) {
  return left.layer < right.layer;
}