#include "frequency.hpp"
#include "utils/utils.hpp"
#include <cmath>

auto frequency(std::span<const uint8_t> data) -> std::tuple<double, double> {
  auto bits_num = static_cast<int64_t>(data.size()) * 8LL;
  auto ones_num = popcount(data);
  auto bits_sum = 2 * ones_num - bits_num;

  auto statistic = static_cast<double>(std::abs(bits_sum)) / std::sqrt(bits_num);
  auto pvalue = std::erfc(statistic / std::sqrt(2.0));

  return {statistic, pvalue};
}
