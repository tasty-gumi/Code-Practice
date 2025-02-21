/*
 * @lc app=leetcode.cn id=918 lang=rust
 *
 * [918] 环形子数组的最大和
 */

// @lc code=start
use std::cmp::{max, min};
impl Solution {
    pub fn max_subarray_sum_circular(nums: Vec<i32>) -> i32 {
        //最大环形子数组的出现有两种情况:
        //nums[i:j](0<=i<j<=n)是一个最大和，此时不考虑环形情况
        //nums[0:i]与nums[j:n]的组合(0<i&&j<n),但此种情况相当于第一种情况求一个连续最小和
        //pre_max 或者pre_min表示的是 模拟了f(i-1)以i作结尾的最大连续子数组和
        let mut sum = 0;
        let mut pre_max = 0;
        let mut pre_min = 0;
        let mut max_res = nums[0];
        let mut min_res = nums[0];
        for num in nums {
            pre_max = max(pre_max + num, num);
            pre_min = min(pre_min + num, num);
            max_res = max(max_res, pre_max); //这里就能记录到以每一个位置做结的最大连续子数组最大和
            min_res = min(min_res, pre_min);
            sum += num;
        }
        if max_res < 0 {
            //此种情况下所有元素是小于零的，避免sum-min_res取到空数组
            return max_res;
        }
        max(max_res, sum - min_res)
    }
}
// @lc code=end
