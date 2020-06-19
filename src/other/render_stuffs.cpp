#include "render_stuff.hpp"
#include <utility>
bool operator<(const LayerAndTexture& left, const LayerAndTexture& right) {
  // if (left.layer < right.layer)
  //   return (left.layer < right.layer);
  // else
  //   return (left.texture < right.texture);

  return std::make_pair(left.layer, left.texture) <
         std::make_pair(right.layer, right.texture);
}

bool operator==(const LayerAndTexture& left, const LayerAndTexture& right) {
  return (left.layer == right.layer) && (left.texture == right.texture);
}
