/*
 * @lc app=leetcode.cn id=274 lang=rust
 *
 * [274] H 指数
 */

// @lc code=start
impl Solution {
    //使用二分查找的思想，h指数的答案只可能在[0,citations.len()]之间的某个值
    //选择一个中点mid后启动全元素检索，如果检测到有多于等于mid个元素大于等于mid，则答案在
    //[mid,right]之间，否则，答案在[left,mid)之间
    //时间复杂度O(nlogn) 空间复杂度O(1)
    pub fn h_index(citations: Vec<i32>) -> i32 {
        let mut left = 0;
        let mut right = citations.len();
        let mut mid = 0;
        let mut cnt = 0;
        while left < right {
            //由于每次舍弃左区间的时候不可以包含mid舍去，所以应该让mid处于二者中间偏后的位置来避免陷入死循环
            mid = (left + right + 1) / 2;
            cnt = 0;
            for &cit in &citations {
                if cit as usize >= mid {
                    cnt += 1;
                }
            }
            if cnt >= mid {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        left as i32
    }
}
// @lc code=end
