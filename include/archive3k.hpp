#ifndef ARCHIVE_3K_HPP_
#define ARCHIVE_3K_HPP_

#include <bits/stdint-intn.h>
#include <common.hpp>

/* 3028. Ant on the Boundary */
auto returnToBoundaryCount(
  std::vector<int>& nums)
  -> int;

/* 3029. Minimum Time to Revert Word to Initial State I */
int minimumTimeToInitialState(
  std::string word,
  int k);
/* 3029. Minimum Time to Revert Word to Initial State I
 * Optimize time consumption by not expoiting sub-string from word.
 */
int minimumTimeToInitialState_O1(
  std::string word,
  int k);

#endif
