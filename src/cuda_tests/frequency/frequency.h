#include <cstdint>
#include <cstdio>
#include <cuda_runtime.h>
#include <span>

__global__ auto iota(std::span<uint8_t> data) -> void;
__global__ auto byte_popc(std::span<const uint8_t> data, std::span<uint8_t> counts) -> void;
