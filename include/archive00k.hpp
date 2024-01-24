#ifndef ARCHIVE00K_HPP_
#define ARCHIVE00K_HPP_

#include <common.hpp>

void p1();
auto p1_twoSum(
  vector<int>& nums,
  int target)
  -> vector<int>;
auto p1_twoSum_o1(
  vector<int>& nums,
  int target)
  -> vector<int>;

void p2();
auto p2_addTwoNumbers(
  ListNode * l1,
  ListNode * l2)
  -> ListNode *;
auto p2_addTwoNumbers(
  ListNode * l1,
  ListNode * l2,
  int carry)
  -> ListNode *;
auto p2_addTwoNumbers_o1(
  ListNode * l1,
  ListNode * l2)
  -> ListNode *;

auto p70_solve(
  const int & n)
  -> int;

auto p108_input()
  -> std::vector<VI>;
auto p108_sortedArrayToBST(
  const VI & nums,
  int start,
  int end)
  -> TreeNode *;
auto p108_sortedArrayToBST(
  const VI & nums)
  -> TreeNode *;

auto p812_input()
  -> std::vector<VVI>;
double p812_largestTriangleArea(
  VVI & points);

#endif
