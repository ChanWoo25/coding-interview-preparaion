#include <archive.hpp>



auto Solution::p812_input()
  -> std::vector<VVI>
{
  std::vector<VVI> inputs;
  inputs.push_back({{0,0},{0,1},{1,0},{0,2},{2,0}});
  inputs.push_back({{0,0},{0,1},{1,0}});
  return inputs;
}

double Solution::p812_largestTriangleArea(
  std::vector<std::vector<int>> & points)
{
  // 3D cross product of OA and OB vectors, (i.e z-component of their "2D" cross product, but remember that it is not defined in "2D").
  // Returns a positive value, if OAB makes a counter-clockwise turn,
  // negative for clockwise turn, and zero if the points are collinear.
  auto cross
    = [](const Point & O,
         const Point & A,
         const Point & B)
         -> double
    {
      return (A.x - O.x) * (B.y - O.y)
           - (A.y - O.y) * (B.x - O.x);
    };

  // Returns a list of points on the convex hull in counter-clockwise order.
  // Note: the last point in the returned list is the same as the first one.
  auto find_convex_hull
    = [&](std::vector<Point> & points)
      -> std::vector<Point>
    {
      const int N = static_cast<int>(points.size());
      if (N <= 3) { return points; }

      std::vector<Point> selected(2*N);
      int k = 0;

      // Sort points lexicographically
      sort(points.begin(), points.end());

      // Build lower hull
      for (int i = 0; i < N; ++i)
      {
        while (   k >= 2
               && cross(selected[k-2],
                        selected[k-1],
                        points[i]) <= 0)
        {
          k--;
        }
        selected[k++] = points[i];
      }

      // Build upper hull
      for (int i = N - 1, t = k + 1; i > 0; --i)
      {
        while (   k >= t
               && cross(selected[k-2],
                        selected[k-1],
                        points[i-1]) <= 0)
        {
          k--;
        }
        selected[k++] = points[i-1];
      }

      spdlog::info("Resize ({}) => ({})", points.size(), k-1);
      selected.resize(k-1);
      return selected;
    };

  // Method 1
  // O(N^3) Compare All 3Pn Combination
  auto get_triangle_area
    = [](const double & x1, const double & y1,
         const double & x2, const double & y2,
         const double & x3, const double & y3)
         -> double
    {
      auto tmp = x1*y2 + x2*y3 + x3*y1
               - x2*y1 - x3*y2 - x1*y3;
      return 0.5 * std::abs(tmp);
    };

  std::vector<Point> points_(points.size());
  for (size_t i = 0; i < points.size(); i++)
  {
    points_[i].x = points[i][0];
    points_[i].y = points[i][1];
  }

  points_ = find_convex_hull(points_);
  for (size_t i = 0; i < points_.size(); i++)
  {
    points[i][0] = points_[i].x;
    points[i][1] = points_[i].y;
  }
  points.resize(points_.size());

  const int N = static_cast<int>(points.size());
  int i1, i2, i3;
  double max_area = -1.0;
  for (i1 = 0; i1 < N - 2; ++i1)
  {
    for (i2 = i1 + 1; i2 < N - 1; ++i2)
  {
      for (i3 = i2 + 1; i3 < N; ++i3)
      {
        const auto x1 = points[i1][0];
        const auto y1 = points[i1][1];
        const auto x2 = points[i2][0];
        const auto y2 = points[i2][1];
        const auto x3 = points[i3][0];
        const auto y3 = points[i3][1];
        double area = get_triangle_area(x1, y1, x2, y2, x3, y3);
        max_area = std::max(max_area, area);
      }
    }
  }
  return max_area;
}

int Solution::p10035_areaOfMaxDiagonal(
  std::vector<std::vector<int>>& dimensions)
{
  double max_diag2 = std::numeric_limits<double>::min();
  double wh_diff = -1.0;
  double area = -1.0;
  for (const auto & wh: dimensions)
  {
      const auto w = static_cast<double>(wh[0]);
      const auto h = static_cast<double>(wh[1]);

      const auto diag2 = std::pow(w,2) + std::pow(h,2);
      if (max_diag2 < diag2)
      {
        max_diag2 = diag2;
        wh_diff = std::abs(w - h);
        area = w * h;
      }
      else if (std::abs(max_diag2 - diag2) < DBL_EPS)
      {
        if (wh_diff > std::abs(w - h))
        {
          wh_diff = std::abs(w - h);
          area = w * h;
        }
      }
  }

  return area;
}

  // auto input00 = VVI();
  // input00.push_back({9, 3});
  // input00.push_back({8, 6});

  // auto output00 = Solution::p10035_areaOfMaxDiagonal(input00);
  // spdlog::info("Answer00: {}", output00);

  // auto input01 = VVI();
  // input01.push_back({3, 4});
  // input01.push_back({4, 3});

  // auto output01 = Solution::p10035_areaOfMaxDiagonal(input01);
  // spdlog::info("Answer01: {}", output01);

/**
 * @brief on 8x8 chessboard with given rook, bishop, queen coord
 * 3번을 움직여야 하는 경우는 없다.
 * bishop은 rook 2번을 대체할 수도있지만, 절반밖에 커버하지 못한다.
 * 1. rook으로 바로 잡을 수 있는 경우. => 1
 * 2. rook과 직선상, 사이에 비숍이 있는 경우, => 2
 * 3. Otherwise, bishop과의 직선거리 상에 rook이 있지 않은 이상,
                 모든 경우에 rook이 2번 안에 잡을 수 있음.
 *
 복기
 - 조건문이 많은 것은 둘째치고, 일관성이 부족하다.
 - 1번 혹은 2번만이 답이 될 수 있음을 사전에 알고 있다면, 반복문 따위보다는
   조건문으로 푸는 것이 좋다. 또한 경우의 수가 적은 1번 Case를 앞으로 빼고,
   2번은 Else 문으로 넘기려고 목표를 정해놓고 구현했으면 좀 더 Clear했을 것이다.
 */
int Solution::p10036_minMovesToCaptureTheQueen(
  int a, int b,
  int c, int d,
  int e, int f)
{
  int rx = a, ry = b; // rook
  int bx = c, by = d; // bishop
  int qx = e, qy = f; // queen
  spdlog::info("rook ({}, {})", rx, ry);
  spdlog::info("bishop ({}, {})", bx, by);
  spdlog::info("queen ({}, {})", qx, qy);
  if ((rx == qx && rx != bx) || // Case 1
      (ry == qy && ry != by))
  {
    return 1;
  }
  else if (rx == qx && rx == bx) // Case 2
  {
    if ((by < ry && by < qy) ||
        (by > ry && by > qy))
    {
      return 1;
    }
  }
  else if (ry == qy && ry == by) // Case 2
  {
    if ((bx < rx && bx < qx) ||
        (bx > rx && bx > qx))
    {
      return 1;
    }
  }
  else
  {
    if ((qx + qy) % 2 != (bx + by) % 2) // Never
    {
      return 2;
    }
    if (std::abs(bx - qx) != std::abs(by - qy)) // Same line
    {
      return 2;
    }
    else
    {
      int xstep = (qx - bx) / std::abs(bx - qx);
      int ystep = (qy - by) / std::abs(by - qy);
      spdlog::info("xstep={}, ystep={}", xstep, ystep);
      for (int x = bx, y = by; x != qx; x += xstep, y += ystep)
      {
        if (x == rx && y == ry)
        {
          return 2;
        }
      }
      return 1;
    }
    return 2;
  }

  return 2;
}
