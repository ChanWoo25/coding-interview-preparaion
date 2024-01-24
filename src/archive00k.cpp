#include "common.hpp"
#include <archive00k.hpp>
#include <cstddef>
#include <unordered_map>

void p1()
{
  VVI nums; VI targets;
  nums.push_back({2, 7, 11, 15});
  nums.push_back({3, 2, 4});
  nums.push_back({3, 3});
  targets.push_back(9);
  targets.push_back(6);
  targets.push_back(6);
  spdlog::info("[p1_twoSum]");
  for (size_t i = 0; i < nums.size(); ++i) {
    auto ans = p1_twoSum(nums[i], targets[i]);
    spdlog::info("ans: ({}, {})", ans[0], ans[1]);
  }
  spdlog::info("[p1_twoSum_o1]");
  for (size_t i = 0; i < nums.size(); ++i) {
    auto ans = p1_twoSum_o1(nums[i], targets[i]);
    spdlog::info("ans: ({}, {})", ans[0], ans[1]);
  }
}
auto p1_twoSum(
  vector<int>& nums,
  int target)
  -> vector<int>
{
  int i1 {0};
  int i2 {1};
  int N = static_cast<int>(nums.size());
  for (; i1 < N - 1; ++i1)
  {
    for (i2 = i1 + 1; i2 < N; ++i2)
    {
      if (nums[i1] + nums[i2] == target)
      {
        std::vector<int> ans {i1, i2};
        return ans;
      }
    }
  }

  std::cerr << "There is no answer!\n";
  return std::vector<int>();
}
auto p1_twoSum_o1(
  vector<int>& nums,
  int target)
  -> vector<int>
{
  const int N = static_cast<int>(nums.size());
  unordered_map<int, int> index_db;

  /* Building Hash Table */
  for (int i = 0; i < N; ++i) {
    index_db[nums[i]] = i;
  }

  /* Searching */
  for (int i = 0; i < N; ++i) {
    const auto residual = target - nums[i];
    if (index_db.count(residual) && index_db[residual] != i)
    {
      return std::vector<int>({i, index_db[residual]});
    }
  }

  /* Exception */
  std::cerr << "There is no answer!\n";
  return std::vector<int>();
}


void p2()
{

}
auto p2_addTwoNumbers(
  ListNode * l1,
  ListNode * l2)
  -> ListNode *
{
  int sum = 0;
  if (l1 != nullptr) { sum += l1->val; }
  if (l2 != nullptr) { sum += l2->val; }

  ListNode * p = new ListNode(sum % 10);
  p->next = (sum >= 10)
          ? p2_addTwoNumbers(l1->next, l2->next, 1)
          : p2_addTwoNumbers(l1->next, l2->next, 0);
  return p;
}
auto p2_addTwoNumbers(
  ListNode * l1,
  ListNode * l2,
  int carry)
  -> ListNode *
{
  if (l1 == nullptr && l2 == nullptr && carry == 0)
  {
    return nullptr;
  }

  int sum = 0;
  if (l1 != nullptr) { sum += l1->val; }
  if (l2 != nullptr) { sum += l2->val; }
  sum += carry;

  ListNode * p = new ListNode(sum % 10);
  auto next1 = (l1)?(l1->next):(nullptr);
  auto next2 = (l2)?(l2->next):(nullptr);
  p->next = (sum >= 10)
          ? p2_addTwoNumbers(next1, next2, 1)
          : p2_addTwoNumbers(next1, next2, 0);
  return p;
}
auto p2_addTwoNumbers_o1(
  ListNode * l1,
  ListNode * l2)
  -> ListNode *
{
  ListNode * head = new ListNode();     //new list;
  ListNode * tail = head;
  int carry = 0;

  /* Traverse both list */
  while (l1 != nullptr ||  l2 != nullptr || carry)
  {
    int sum = 0;

    // if l1  is not null
    // add l1-> value to sum
    if(l1 != nullptr)
    {
      sum += l1->val;
      l1 = l1 -> next;
    }

    // if l2  is not null
    // add l2-> value to sum
    if(l2 != nullptr)
    {
      sum += l2->val;
      l2 = l2 -> next;
    }

    // add carry to sum
    sum += carry;

    // carry is updated by sum/10 because for 18 ,
    // 18 / 10 is 1 which is the carry
    carry = sum / 10;

    // add sum% 10 to new node as it containg the sum
    ListNode * node = new ListNode(sum%10);
    tail->next = node;
    tail = tail->next;
  }

  return head->next;
}


auto p70_solve(
  const int & n)
  -> int
{
  /* Ver 1: Recursion */
  // if (n == 0 || n == 1)
  // {
  //   return 1;
  // }
  // return climbStairs(n-1) + climbStairs(n-2);

  /* Ver 2: Memorization */
  // if (n == 0 || n == 1)
  // {
  //   return 1;
  // }
  // if (memo.find(n) == memo.end())
  // {
  //   memo[n] = climbStairs(n-1, memo)
  //           + climbStairs(n-2, memo);
  // }
  // return memo[n];

  /* Ver 3: Dynamic Programming */
  // if (n == 0 || n == 1)
  // {
  //   return 1;
  // }
  // std::vector<int> dp(n+1);
  // dp[0] = dp[1] = 1;
  // for (int i = 2; i <= n; i++)
  // {
  //   dp[i] = dp[i-1] + dp[i-2];
  // }
  // return dp[n];

  /* Ver 4: Dynamic Programming
          + Space Optimization */
  if (n == 0 || n == 1)
  {
    return 1;
  }
  int prev = 1, curr = 1;
  for (int i = 2; i <= n; i++)
  {
    int temp = curr;
    curr = prev + curr;
    prev = temp;
  }
  return curr;
}

auto p108_input()
  -> std::vector<VI>
{
  std::vector<VI> inputs;
  inputs.push_back({-10, -3, 0, 5, 9});
  inputs.push_back({1, 3});
  return inputs;
}

auto p108_sortedArrayToBST(
  const VI & nums,
  int start,
  int end)
  -> TreeNode *
{
  if (end < start)
  {
    return NULL;
  }
  else if (end == start)
  {
    return new TreeNode(nums[start]);
  }
  else
  {
    int median = (start + end) / 2;
    TreeNode * root = new TreeNode(nums[median]);
    root->left  = p108_sortedArrayToBST(nums, start, median - 1);
    root->right = p108_sortedArrayToBST(nums, median + 1, end);
    return root;
  }
}

auto p108_sortedArrayToBST(
  const VI & nums)
  -> TreeNode *
{
  const auto N
    = static_cast<int>(nums.size());
  return p108_sortedArrayToBST(nums, 0, N - 1);
}

auto p812_input()
  -> std::vector<VVI>
{
  std::vector<VVI> inputs;
  inputs.push_back({{0,0},{0,1},{1,0},{0,2},{2,0}});
  inputs.push_back({{0,0},{0,1},{1,0}});
  return inputs;
}

double p812_largestTriangleArea(
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
