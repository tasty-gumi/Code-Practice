/*
 * @lc app=leetcode.cn id=3066 lang=rust
 *
 * [3066] 超过阈值的最少操作数 II
 */

// @lc code=start
use std::collections::BinaryHeap; //使用默认的大根堆实现优先队列

impl Solution {
    pub fn min_operations(nums: Vec<i32>, k: i32) -> i32 {
        //这里输入都是正整数，为了方便都取反之后插入优先队列
        let mut priority_queue: BinaryHeap<i32> = BinaryHeap::new();
        for num in nums {
            priority_queue.push(-num);
        }
        let mut count = 0;
        while let Some(min) = priority_queue.pop() {
            if min == i32::MIN || -min >= k {
                break;
            }
            // 完成一次操作
            if let Some(second) = priority_queue.pop() {
                if min < -i32::MAX / 2 || 2 * (-min) > i32::MAX + second {
                    //处理可能有的溢出
                    priority_queue.push(i32::MIN)
                } else {
                    priority_queue.push(min * 2 + second);
                }
                count += 1;
            }
        }
        count
    }
}
// @lc code=end
