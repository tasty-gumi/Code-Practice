/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  void get_feature(const string &s, string &feature) {
    int dir[26] = {0};
    for (const auto &ch : s) {
      dir[ch - 'a']++;
    }
    for (int i = 0; i < 26; ++i) {
      if (dir[i] > 0) {
        string append;
        append.assign(dir[i], (char)('a' + i));
        feature += append;
      }
    }
  }
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> feat;
    for (const auto &s : strs) {
      string feature = "";
      get_feature(s, feature);
      if (!feat.count(feature)) {
        feat.emplace(feature, vector<string>{s});
      } else {
        feat[feature].emplace_back(s);
      }
    }
    vector<vector<string>> res(feat.size());
    int c = 0;
    for (auto &[feat, vec] : feat) {
      res[c++].swap(vec);
    }
    return res;
  }
};
// @lc code=end
