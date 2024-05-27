#include "frequency.h"

__global__ auto iota(std::span<uint8_t> data) -> void {
  auto tid = blockIdx.x * blockDim.x + threadIdx.x;
  if (tid < data.size()) {
    data[tid] = tid;
  }
}
__global__ auto byte_popc(std::span<const uint8_t> data, std::span<uint8_t> counts) -> void {
  auto tid = blockIdx.x * blockDim.x + threadIdx.x;
  if (tid < data.size()) {
    counts[tid] = __popc(data[tid]);
  }
}
