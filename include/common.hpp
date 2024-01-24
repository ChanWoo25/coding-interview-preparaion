#ifndef COMMON_HPP_
#define COMMON_HPP_

#include <spdlog/common.h>
#include <spdlog/spdlog.h>

#include <iostream>
#include <cmath>
#include <numeric>
#include <limits>
#include <vector>
#include <unordered_map>

constexpr float  FLT_EPS = 0.00000001F; // 1e-8
constexpr double DBL_EPS = 0.00000001;  // 1e-8

using namespace std;
using VI  = vector<int>;
using VVI = vector<VI>;

struct Point {
  double x, y;
  bool operator < (const Point & point)
  {
    return (x < point.x)
        || (x == point.x && y < point.y);
  }
};

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode * left;
  TreeNode * right;
  TreeNode()
           : val(0),
             left(nullptr),
             right(nullptr) {}
  TreeNode(int x)
           : val(x),
             left(nullptr),
             right(nullptr) {}
  TreeNode(int x,
           TreeNode * left,
           TreeNode * right)
           : val(x),
             left(left),
             right(right) {}
};
/* Definition for singly-linked list. */
struct ListNode {
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode * next) : val(x), next(next) {}
  int val;
  ListNode * next;
};

#endif
