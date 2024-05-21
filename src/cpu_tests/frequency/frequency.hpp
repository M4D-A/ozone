#include <cstdint>
#include <span>
#include <tuple>

auto frequency(std::span<const uint8_t>) -> std::tuple<double, double>;
