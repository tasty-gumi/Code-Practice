/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */
#include <mutex>
#include <queue>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  bool canVisitAllRooms(vector<vector<int>> &rooms) {
    int n = rooms.size();
    vector<bool> visited(n, false);
    queue<short> viq;
    viq.emplace(0);
    visited[0] = true;
    int count = 1;
    while (!viq.empty()) {
      int c = viq.size();
      for (int i = 0; i < c; ++i) { // 每个房间
        auto &locks = rooms[viq.front()];
        for (const auto &lock : locks) { // 每个房间中的每把锁
          if (!visited[lock]) {
            viq.emplace(lock);
            visited[lock] = true;
            ++count;
          }
        }
        viq.pop();
      }
    }
    return count == n;
  }
};
// @lc code=end
