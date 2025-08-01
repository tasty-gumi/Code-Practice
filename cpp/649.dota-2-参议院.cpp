/*
 * @lc app=leetcode.cn id=649 lang=cpp
 *
 * [649] Dota2 参议院
 */
#include <queue>
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
  string predictPartyVictory(string senate) {
    const unsigned short n = senate.size();
    queue<unsigned short> rediant;
    queue<unsigned short> dire;
    // 存储一下两队议员的优先级号，号码小的优先级高
    for (unsigned short i = 0; i < n; ++i) {
      senate[i] == 'R' ? (rediant.push(i)) : (dire.push(i));
    }
    while (!rediant.empty() && !dire.empty()) {
      // 对两队进行处理当优先级较高时，将优先级降低一轮的轮次添加末尾
      rediant.front() > dire.front() ? (dire.push(dire.front() + n))
                                     : (rediant.push(rediant.front() + n));
      rediant.pop();
      dire.pop();
    }
    return rediant.empty() ? ("Dire") : ("Radiant");
  }
};
// @lc code=end
