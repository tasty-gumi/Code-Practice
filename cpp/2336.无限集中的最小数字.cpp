/*
 * @lc app=leetcode.cn id=2336 lang=cpp
 *
 * [2336] 无限集中的最小数字
 */
#include <set>
using namespace std;

// @lc code=start
class SmallestInfiniteSet {
public:
  SmallestInfiniteSet() {}

  int popSmallest() {
    int res = 0;
    if (!nums.empty()) {
      // 红黑树最小的那个
      nums.erase(res = *nums.begin());
    } else {
      res = min_res++;
    }
    return res;
  }

  void addBack(int num) {
    if (num < min_res) {
      nums.emplace(num);
    }
  }

private:
  set<unsigned short> nums;
  int min_res = 1; // 大于等于这个的数都有
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
// @lc code=end
