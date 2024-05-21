#include "cpu_tests/frequency/frequency.hpp"
#include <iostream>
#include <vector>

auto main() -> int {
  // NOLINTNEXTLINE
  auto data = std::vector<uint8_t>{0x12, 0x34, 0xde, 0xad, 0xbe, 0xef, 0x12, 0x34};

  auto [a, b] = frequency(data);
  std::cout << a << " " << b << "\n";
}
