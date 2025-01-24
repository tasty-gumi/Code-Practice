/*
 * @lc app=leetcode.cn id=3095 lang=rust
 *
 * [3095] 或值至少 K 的最短子数组 I
 */

// @lc code=start
impl Solution {
    pub fn minimum_subarray_length(nums: Vec<i32>, k: i32) -> i32 {
        // 这里k是小于64的一个非负值，故记录k的每一位上是否有1
        // 思路就是先遍历nums数组，记录nums元素每位上出现1的次数，然后用双指针缩减nums长度，每次如果不会使结果小于等于k则缩减
        let mut bits: [i32; 6] = [0; 6];
        let mut res = i32::MAX;
        let n = nums.len();
        let cal_bit = |bits: &[i32]| -> i32 {
            //计算一个bits数组的或运算值
            let mut ans = 0;
            for i in 0..6 {
                if bits[i] > 0 {
                    //i位上至少一个1
                    ans |= (1 << i);
                }
            }
            ans
        };
        let mut left = 0;
        for right in 0..n {
            //窗口大小递增
            for i in 0..6 {
                bits[i] += (nums[right] >> i) & 1; //bits为子数组所有位置二进制1的和
            }
            while left <= right && cal_bit(&bits) >= k {
                //当前bists值满足，尝试缩进左边界
                res = res.min((right - left + 1) as i32); //当前子数组长度
                for i in 0..6 {
                    bits[i] -= (nums[left] >> i) & 1;
                }
                left += 1;
            }
        }
        if res == i32::MAX {
            -1
        } else {
            res
        }
    }
}
// @lc code=end
