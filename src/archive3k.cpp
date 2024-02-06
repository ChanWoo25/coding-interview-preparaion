#include <archive3k.hpp>
#include <cstddef>

auto returnToBoundaryCount(
  std::vector<int>& nums)
  -> int
{
  int ans = 0;
  std::vector<int> accumulated;
  accumulated.resize(nums.size());

  accumulated[0] = nums[0];
  for (size_t i = 1; i < nums.size(); ++i)
  {
    accumulated[i] = accumulated[i-1] + nums[i];
    if (accumulated[i] == 0) { ++ans; }
  }

  return ans;
}

int minimumTimeToInitialState(
  std::string word,
  int k)
{
  int pos = 0;
  int ans = 0;
  int N = static_cast<int>(word.size());
  while (true)
  {
    ++ans;
    pos += k; N -= k;

    if (N <= 0) { return ans; }
    else if (word.substr(0, N) == word.substr(pos, N))
    {
      return ans;
    }
  }
}

int minimumTimeToInitialState_O1(
  std::string word,
  int k)
{
  int ans = 1;
  int N = static_cast<int>(word.size());
  for (int pos = k; pos < N; pos += k)
  {
    for (int i = 0; i < N - pos; ++i)
    {
      if (word[i] != word[pos + i]) { break; }
      if (pos + i == N - 1) { return ans; }
    }
    ++ans;
  }

  return N / k
         + ((N % k == 0) ? 0 : 1);
}
