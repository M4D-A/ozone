#include "cpu/frequency/frequency.hpp"
#include <iostream>
#include <vector>

int main() {
  auto data = std::vector<uint64_t>{0x1234deadbeef1234, 0x1cad2cad3cad4bad};
  auto [a, b] = frequency(data);
  std::cout << a << " " << b << "\n";
}
