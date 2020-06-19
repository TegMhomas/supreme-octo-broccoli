#include "render_stuff.hpp"

bool operator<(const LayerAndTexture& left, const LayerAndTexture& right) {
  if (left.layer < right.layer)
    return (left.layer < right.layer);
  else
    return (left.texture < right.texture);
}

bool operator==(const LayerAndTexture& left, const LayerAndTexture& right) {
  return (left.layer == right.layer) && (left.texture == right.texture);
}
