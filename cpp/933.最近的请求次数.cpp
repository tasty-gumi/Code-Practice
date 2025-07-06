/*
 * @lc app=leetcode.cn id=933 lang=cpp
 *
 * [933] 最近的请求次数
 */
#include <queue>
// @lc code=start
class RecentCounter {
public:
  RecentCounter() {}

  int ping(int t) {
    while (!timestmp.empty() && timestmp.front() < t - 3000) {
      timestmp.pop();
    }
    timestmp.push(t);
    return timestmp.size();
  }

private:
  std::queue<int> timestmp = {};
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end
