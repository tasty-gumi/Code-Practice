/*
 * @lc app=leetcode.cn id=480 lang=cpp
 *
 * [480] 滑动窗口中位数
 */
#include <functional>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  vector<double> medianSlidingWindow(vector<int> &nums, int k) {
    vector<double> res;
    int n = nums.size();
    for (int i = 0; i < k; ++i) {
      insert(nums[i]);
    }
    int pos = k - 1;
    while (pos < n) {
      res.emplace_back(
          k & 1
              ? (l_max_heap.top())
              : (((double)l_max_heap.top() + (double)r_min_heap.top()) / 2.0));
      if (++pos < n) {
        remove(nums[pos - k]);
        insert(nums[pos]);
      }
    }
    return res;
  }
  // 插入时，将元素放置到其中一边，触发平衡
  void insert(int val) {
    if (l_max_heap.empty() || val <= l_max_heap.top()) {
      l_max_heap.emplace(val);
      ++lc;
    } else {
      r_min_heap.emplace(val);
      ++rc;
    }
    make_balance();
  }
  // 删除时置标记，减少计数并仅在条件下修剪队列
  void remove(int tar) {
    // 先打上删除标记，如果堆顶元素就是待删除元素，对对应堆执行一次修剪，不是的话可能延迟到平衡时删除
    dvc[tar]++;
    if (tar <= l_max_heap.top()) {
      --lc;
      if (tar == l_max_heap.top()) {
        prune(l_max_heap);
      }
    } else {
      --rc;
      if (tar == r_min_heap.top()) {
        prune(r_min_heap);
      }
    }
    make_balance();
  }
  // 修剪堆，如果堆顶元素是标记删除值，则将它从堆中移除
  template <typename T> void prune(T &heap) {
    while (!heap.empty()) {
      int tar = heap.top();
      if (dvc.count(tar)) {
        if (--dvc[tar] == 0) {
          dvc.erase(tar);
        }
        heap.pop();
      } else {
        break;
      }
    }
  }
  // 使两个堆保持元素数量之差为0或者1
  void make_balance() {
    if (lc > rc + 1) {
      r_min_heap.emplace(l_max_heap.top());
      l_max_heap.pop();
      --lc;
      ++rc;
      prune(l_max_heap);
    } else if (rc > lc) {
      l_max_heap.emplace(r_min_heap.top());
      r_min_heap.pop();
      --rc;
      ++lc;
      prune(r_min_heap);
    }
  }

private:
  priority_queue<int, vector<int>, std::less<int>> l_max_heap;
  priority_queue<int, vector<int>, std::greater<int>> r_min_heap;
  int lc = 0, rc = 0; // 左右两个堆分别逻辑持有的元素
  unordered_map<int, int> dvc;
};
// @lc code=end
