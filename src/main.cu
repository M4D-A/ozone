#include "cuda_tests/frequency/frequency.h"
#include <cstdint>
#include <cuda_device_runtime_api.h>
#include <cuda_runtime.h>
#include <iostream>
#include <ranges>
#include <span>

namespace rv = std::ranges::views;

auto main() -> int {
  int N = 25600;

  uint8_t *data_ptr = nullptr;
  uint8_t *output_ptr = nullptr;
  cudaMallocManaged(&data_ptr, N * sizeof(uint8_t));
  cudaMallocManaged(&output_ptr, N * sizeof(uint8_t));

  std::span<uint8_t> data(data_ptr, N);
  std::span<uint8_t> output(data_ptr, N);

  int block_size = 256;
  int blocks_num = (N - 1) / block_size + 1;

  iota<<<blocks_num, block_size>>>(data);
  byte_popc<<<blocks_num, block_size>>>(data, output);
  cudaDeviceSynchronize();

  for (auto count : output | rv::take(10)) {
    std::cout << (int)count << ", ";
  }
  std::cout << "\n";

  for (auto count : output | rv::reverse | rv::take(10)) {
    std::cout << (int)count << ", ";
  }
  std::cout << "\n";

  return 0;
}
