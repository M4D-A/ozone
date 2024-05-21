#include <cstdint>
#include <span>
#include <tuple>

auto frequency(std::span<const uint64_t> data) -> std::tuple<double, double>;
