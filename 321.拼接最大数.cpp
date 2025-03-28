/*
 * @lc app=leetcode.cn id=321 lang=cpp
 *
 * [321] 拼接最大数
 */

// @lc code=start
class Solution {
public:
  vector<int> maxNumber(vector<int> &nums1, vector<int> &nums2, int k) {
    vector<int> res;
    int total_remove = nums1.size() + nums2.size() - k;
    vector<int> nums1stack;
    vector<int> nums2stack;
    int lp = 0, rp = 0;

    // 构造单调递减栈
    while (total_remove > 0) {
      while (lp < nums1.size() &&
             (nums1stack.empty() || nums1stack.back() >= nums1[lp])) {
        nums1stack.push_back(nums1[lp++]);
      }
      while (rp < nums2.size() &&
             (nums2stack.empty() || nums2stack.back() >= nums2[rp])) {
        nums2stack.push_back(nums2[rp++]);
      }

      // 比较原始数组的当前元素
      if (lp < nums1.size() && rp < nums2.size()) {
        if (compare(nums1, lp, nums2, rp)) {
          nums2stack.pop_back();
        } else {
          nums1stack.pop_back();
        }
      } else if (lp < nums1.size()) {
        nums1stack.pop_back();
      } else if (rp < nums2.size()) {
        nums2stack.pop_back();
      }
      --total_remove;
    }

    // 将剩余元素加入栈
    while (lp < nums1.size()) {
      nums1stack.push_back(nums1[lp++]);
    }
    while (rp < nums2.size()) {
      nums2stack.push_back(nums2[rp++]);
    }

    // 合并两个栈
    lp = 0;
    rp = 0;
    while (k--) {
      if (lp < nums1stack.size() && rp < nums2stack.size()) {
        if (compare(nums1, lp, nums2, rp)) {
          res.push_back(nums1stack[lp++]);
        } else {
          res.push_back(nums2stack[rp++]);
        }
      } else if (lp < nums1stack.size()) {
        res.push_back(nums1stack[lp++]);
      } else {
        res.push_back(nums2stack[rp++]);
      }
    }
    return res;
  }

private:
  bool compare(const vector<int> &nums1, int i, const vector<int> &nums2,
               int j) {
    // 比较从索引 i 和 j 开始的两个数组
    while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
      ++i;
      ++j;
    }
    return j == nums2.size() ||
           (i < nums1.size() && (j == nums2.size() || nums1[i] > nums2[j]));
  }
};
// @lc code=end
