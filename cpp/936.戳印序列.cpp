/*
 * @lc app=leetcode.cn id=936 lang=cpp
 *
 * [936] 戳印序列
 */
#include <algorithm>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
// 记录当前的长为stamp长度的窗口能够翻转哪些下标处的字符，还有哪些不能被翻转
struct Window {
  unordered_set<short> made, todo;
  Window(unordered_set<short> &&made_, unordered_set<short> &&todo_)
      : made(made_), todo(todo_) {};
};
class Solution {
public:
  vector<int> movesToStamp(string stamp, string target) {
    short n = target.size(), turns = 10 * n, len = stamp.size(); // n∈[1,1000]
    vector<Window> windows;
    unordered_set<short> made, todo;
    vector<int> ans;
    vector<bool> done(n, false); // 已经被翻转回？的位置
    queue<short> qu; // 被翻转回？的下标队列，按照FIFO的原则，用队列保证顺序
    for (short i = 0; i <= n - len; ++i) {
      made.clear();
      todo.clear();
      for (short j = 0; j < len; ++j) {
        target[i + j] == stamp[j] ? (made.emplace(i + j))
                                  : (todo.emplace(i + j));
      }
      if (todo.empty()) { // 找到了全部匹配的将窗口中的字符全部翻转回?,被翻转的下标入队并记录
        ans.emplace_back(i);
        for (short k = i; k < i + len; ++k) {
          if (!done[k]) {
            qu.emplace(k);
            done[k] = true;
          }
        }
      }
      windows.emplace_back(std::move(made), std::move(todo));
    }
    while (!qu.empty()) {
      short pos = qu.front(); // 被翻转的下标确定了可能收到影响的窗口id范围
      for (short j = max(0, pos - len + 1); j <= min((short)(n - len), pos);
           ++j) {
        // 将受影响的窗口中tod出现了当前翻转元素的元素删除
        if (windows[j].todo.count(pos)) {
          windows[j].todo.erase(pos);
          if (windows[j].todo.empty()) { // 当前窗口也成功翻转了
            ans.emplace_back(j);
            // 当窗口已经完全被翻转了，将该窗口初始化时保存的made取出看看，没有翻转的翻转并加入队列
            for (const auto &x : windows[j].made) {
              if (!done[x]) {
                qu.emplace(x);
                done[x] = true;
              }
            }
          }
        }
      }
      qu.pop();
    }
    for (const auto &d : done) {
      if (!d) { // 不合预期的行为
        return {};
      }
    }
    // 翻转序和盖章序是相反的
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
// @lc code=end
