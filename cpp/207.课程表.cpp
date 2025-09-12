/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> depend_num(numCourses, 0);
    unordered_map<int, vector<int>> depend_by;
    for (const auto &v : prerequisites) {
      ++depend_num[v[0]];
      depend_by[v[1]].emplace_back(v[0]);
    }
    queue<int> qu;
    for (int i = 0; i < numCourses; ++i) {
      if (!depend_num[i])
        qu.emplace(i);
    }
    int pop_num = 0;
    while (!qu.empty()) {
      int top = qu.front();
      qu.pop();
      ++pop_num;
      if (depend_by.count(top)) {
        for (const auto &neib : depend_by[top]) {
          if (--depend_num[neib] == 0) {
            qu.emplace(neib);
          }
        }
      }
    }
    return pop_num == numCourses;
  }
};
// @lc code=end
