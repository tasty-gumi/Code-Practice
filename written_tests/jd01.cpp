#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

// 题目描述:在1个含有重复数字的数组中，只包含在范围[1,k]的元素(每个数都至少有1个)，
// 现在需要你返还一个包含k个数各1个的子序列(在原数组中删除若干元素的子数组)，
// 使得这个子序列是所有子序列中字典序最小的，比如[2,1,3,3,2]->[1,3,2]
// (字典序2,1,3会大于1,3,2)

vector<int> findMinSubsequence(vector<int> &nums, int k) {
  // 预处理：记录1~k每个数字的所有出现位置（按索引递增）
  vector<vector<int>> pos(k + 1); // pos[num]存储num在nums中出现的索引
  for (int i = 0; i < nums.size(); ++i) {
    int num = nums[i];
    if (num >= 1 && num <= k) { // 只关注1~k的数字
      pos[num].push_back(i);
    }
  }

  vector<int> result;
  int last_pos = -1;  // 上一个选中数字的位置（初始为-1，代表从数组开头开始）
  set<int> remaining; // 剩余需要包含的数字（有序存储，便于从小到大遍历）
  for (int i = 1; i <= k; ++i) {
    remaining.insert(i);
  }

  // 迭代k次，每次确定子序列的一个元素
  for (int step = 0; step < k; ++step) {
    // 从小到大遍历剩余数字，优先选择较小的数字
    for (auto it = remaining.begin(); it != remaining.end(); ++it) {
      int x = *it;                      // 当前候选数字
      const auto &x_positions = pos[x]; // x的所有出现位置

      // 找到x在last_pos之后的第一个出现位置（二分查找）
      auto idx_it =
          upper_bound(x_positions.begin(), x_positions.end(), last_pos);
      if (idx_it == x_positions.end()) {
        continue; // x在last_pos之后无出现，跳过
      }
      int current_pos = *idx_it; // 当前候选位置

      // 检查：current_pos之后是否包含所有剩余数字（除x外）
      bool valid = true;
      for (int y : remaining) {
        if (y == x)
          continue; // 跳过当前候选数字x
        const auto &y_positions = pos[y];
        // 查找y在current_pos之后是否有出现
        auto y_idx_it =
            upper_bound(y_positions.begin(), y_positions.end(), current_pos);
        if (y_idx_it == y_positions.end()) {
          valid = false;
          break; // y在current_pos之后无出现，当前x无效
        }
      }

      if (valid) {
        // 选择x，更新状态
        result.push_back(x);
        remaining.erase(x);
        last_pos = current_pos;
        break; // 进入下一轮选择
      }
    }
  }

  return result;
}

// 测试示例
int main() {
  vector<int> nums1 = {3, 1, 4, 2, 1, 3};
  auto res1 = findMinSubsequence(nums1, 4);
  for (int num : res1)
    cout << num << " "; // 输出：1 4 2 3
  cout << endl;

  vector<int> nums2 = {2, 1, 3, 1, 4};
  auto res2 = findMinSubsequence(nums2, 3);
  for (int num : res2)
    cout << num << " "; // 输出：2 1 3
  cout << endl;

  vector<int> nums3 = {1, 3, 2, 4, 3};
  auto res3 = findMinSubsequence(nums3, 3);
  for (int num : res3)
    cout << num << " "; // 输出：1 2 3
  cout << endl;

  return 0;
}