/*
 * @lc app=leetcode.cn id=952 lang=cpp
 *
 * [952] 按公因数计算最大组件大小
 */
#include <algorithm>
#include <cstddef>
#include <numeric>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  size_t find(size_t x) {
    if (x != parent[x]) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }
  void uni(size_t a, size_t b) {
    size_t roota = find(a);
    size_t rootb = find(b);
    if (roota != rootb) { // 异根有必要合并
      // 优先选择等级本来就高的作为根
      if (rank[roota] > rank[rootb]) {
        parent[rootb] = roota;
      } else if (rank[roota] < rank[rootb]) {
        parent[roota] = rootb;
      } else {
        parent[rootb] = roota;
        rank[roota]++;
      }
    }
  }
  int largestComponentSize(vector<int> &nums) {
    size_t m = *max_element(nums.begin(), nums.end()) + 1;
    parent.resize(m);
    rank.resize(m, 0);
    iota(parent.begin(), parent.end(), 0);
    for (const auto &n : nums) {
      for (size_t i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
          uni(n, i);
          uni(n, n / i);
        }
      }
    }
    // 重用rank作为计数统计数组
    rank.assign(m, 0);
    // C++的vector容器在resize前后如果大小一致，那么他不会使用resize后面的值重置数组导致错误
    // rank.resize(m, 0);
    for (const auto &n : nums) {
      rank[find(n)]++;
    }
    return (int)*max_element(rank.begin(), rank.end());
  }

private:
  // 标识并查集中每个元素所在集合的根节点，初始时，各元素自己即是根
  vector<size_t> parent;
  // 性能优化必须的一个结构，用于表征树的高度，当一颗树合并另一棵树时，等级提升，相当于find函数将会更慢找到根
  vector<size_t> rank;
};
// @lc code=end
