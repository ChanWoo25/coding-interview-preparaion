#ifndef ARCHIVE_HPP_
#define ARCHIVE_HPP_

#include <spdlog/common.h>
#include <spdlog/spdlog.h>

#include <cmath>
#include <numeric>
#include <limits>
#include <vector>
constexpr double DBL_EPS = 0.00000001; // 1e-8

using VI = std::vector<int>;
using VVI = std::vector<VI>;

struct Point {
  double x, y;
  bool operator < (const Point & point)
  {
    return (x < point.x)
        || (x == point.x && y < point.y);
  }
};

class Solution
{
public:
  static auto p812_input()
    -> std::vector<VVI>;
  static
  double p812_largestTriangleArea(
    VVI & points);

  static
  int p10035_areaOfMaxDiagonal(
    std::vector<std::vector<int>>& dimensions);

  static
  int p10036_minMovesToCaptureTheQueen(
    int a, int b, int c, int d, int e, int f);
};
#endif
