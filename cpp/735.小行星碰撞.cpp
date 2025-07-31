/*
 * @lc app=leetcode.cn id=735 lang=cpp
 *
 * [735] 小行星碰撞
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> asteroidCollision(vector<int> &asteroids) {
    vector<int> righting_moving;
    vector<int> total_left;
    bool dead = false;
    for (const auto &a : asteroids) {
      if (a < 0) {
        // 向左边运动，当有右边运动的陨石时，销毁向右移动比他小的陨石
        dead = false;
        while (!righting_moving.empty()) {
          if (righting_moving.back() + a < 0)
            righting_moving.pop_back();
          else if (righting_moving.back() + a == 0) { // 等大销毁
            righting_moving.pop_back();
            dead = true;
            break;
          } else {
            dead = true;
            break;
          }
        }
        // 向右移动的a没有被销毁
        if (!dead)
          total_left.emplace_back(a);
      } else {
        righting_moving.emplace_back(a);
      }
    }
    total_left.insert(total_left.end(), righting_moving.begin(),
                      righting_moving.end());
    return total_left;
  }
};
// @lc code=end
