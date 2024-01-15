//
// Author: Chanwoo Lee (https://github.com/ChanWoo25)
//
#include <archive.hpp>

#include <spdlog/common.h>
#include <spdlog/spdlog.h>
#include <yaml-cpp/yaml.h>

#include <fstream>

int main()
{
  auto inputs = Solution::p108_input();
  for (auto input: inputs)
  {
    const auto output = Solution::p108_sortedArrayToBST(input);
    spdlog::info("Answer: {}", output);
  }

  return EXIT_SUCCESS;
}
