/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
#include <cmath>
#include <new>
#include <unordered_map>
#include <unordered_set>
#include <vector>
class Solution {
public:
  struct Requirements {
    std::unordered_set<int> pre;
    std::unordered_set<int> post;
  };
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    std::unordered_map<int, Requirements *> id2req;
    std::vector<int> zero_pre;
    std::vector<int> res;
    for (int i = 0; i < numCourses; ++i) {
      id2req.insert({i, new Requirements()});
    }
    for (auto prere : prerequisites) {
      auto it_first = id2req.find(prere[0]);
      auto it_second = id2req.find(prere[1]);
      it_first->second->pre.insert(prere[1]);
      it_second->second->post.insert(prere[0]);
    }
    for (auto it = id2req.begin(); it != id2req.end();
         ++it) { // 记录入度为零的节点数量
      if (it->second->pre.empty()) {
        zero_pre.emplace_back(it->first);
      }
    }
    while (!zero_pre.empty()) {
      int cur =
          zero_pre
              .back(); // 每次将一个入度为零(没有前置课程)的节点放入结果数组中
      res.emplace_back(cur);
      zero_pre.pop_back();
      auto it = id2req.find(cur);
      for (
          int post_course :
          it->second
              ->post) { // 遍历每一个此节点的后置节点，在那些节点中删除它作为前置的
        auto iter = id2req.find(post_course);
        iter->second->pre.erase(it->first);
        if (iter->second->pre.empty()) {
          zero_pre.emplace_back(iter->first);
        }
      }
    }
    if (res.size() !=
        numCourses) { // DAG图存在环状结构，使得课程不能被按某种顺序修完
      return {};
    }
    return res;
  }
};
// @lc code=end
