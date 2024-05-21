#include "frequency.hpp"

auto frequency(std::span<const uint64_t> data) -> std::tuple<double, double> {
  return {0.0, data.size()};
}
