#include "utils.hpp"
#include <bit>
#include <numeric>

auto popcount(std::span<const uint8_t> data) -> int64_t {
  auto popcount_accumulate_lambda = [](int64_t current_count, uint8_t byte) {
    return current_count + std::popcount(byte);
  };
  return std::accumulate(data.begin(), data.end(), 0, popcount_accumulate_lambda);
}
