/*
 * @lc app=leetcode.cn id=45 lang=rust
 *
 * [45] 跳跃游戏 II
 */
pub struct Solution;
// @lc code=start

impl Solution {
    pub fn jump(nums: Vec<i32>) -> i32 {
        //  没有使用迭代器实现
        //     // 使用贪心法，如果当前不能一步跳到终点，选择离起点最远，且收益最大的跳法
        //     let mut cur: usize = 0;
        //     let mut res: i32 = 0;
        //     while cur < nums.len() - 1 {
        //         let mut max: usize = 0;
        //         let mut next: usize = 0;
        //         for i in (1..=nums[cur] as usize).rev() {
        //             if cur + i >= nums.len() - 1 {
        //                 return res + 1;
        //             }
        //             // 当前跳跃步数和目标位置可跳跃最大步数的和为收益
        //             if i + nums[cur + i] as usize > max {
        //                 max = i + nums[cur + i] as usize;
        //                 next = cur + i;
        //             }
        //         }
        //         cur = next;
        //         res += 1;
        //     }
        //     res
        // }

        // 使用迭代器的版本
        if nums.len() == 1 {
            return 0;
        }

        let (steps, _, _) = nums.iter().enumerate().take(nums.len() - 1).fold(
            (0, 0, 0),
            |(steps, cur_max_reach, next_max_reach), (i, &i_reach)| {
                let new_max_reach = next_max_reach.max(i + i_reach as usize);
                // 只有当前1位置达到当前最远的位置时，增加跳数
                if i == cur_max_reach {
                    (steps + 1, new_max_reach, new_max_reach)
                } else {
                    (steps, cur_max_reach, new_max_reach)
                }
            },
        );
        steps as i32
    }
}
// @lc code=end
