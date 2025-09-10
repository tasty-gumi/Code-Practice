/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
// @lc code=start
using namespace std;
class Solution {
public:
  int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    vector<vector<int>> dist(m + 1, vector<int>(n + 1, 0));
    iota(dist[0].begin(), dist[0].end(), 0);
    for (int j = 1; j <= m; ++j)
      dist[j][0] = j;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= n; ++j) {
        dist[i][j] =
            (word1[i - 1] == word2[j - 1])
                ? (dist[i - 1][j - 1])
                : (min({dist[i - 1][j],        // 看成添加1个words2的j
                        dist[i][j - 1],        // 看成添加一个words1的i
                        dist[i - 1][j - 1]}) + // 看成替换words1的i与words2的j
                   1);
      }
    }
    return dist[m][n];
  }
};
// @lc code=end
