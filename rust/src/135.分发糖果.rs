/*
 * @lc app=leetcode.cn id=135 lang=rust
 *
 * [135] 分发糖果
 */

// @lc code=start
// 严格区间长度计数，单次遍历
// 思路是记录最近的一个严格单调递增区间的长度，，如果当前处在一个非递减区间之内，根据和前一个位置的关系决定发糖果的数量
// pre的新值总是严格单调递增区间长，若存在严格单调递减区间，发糖果数量与此长度有关
impl Solution {
    pub fn candy(ratings: Vec<i32>) -> i32 {
        // 当前的严格单调区间长
        let mut pre: i32 = 1;
        let mut res: i32 = 1;
        //当前严格单调递减次数
        let mut dec: i32 = 0;
        //记录最近一次严格单调递增区间长度
        let mut inc: i32 = 1;
        for i in 1..ratings.len() {
            if ratings[i] >= ratings[i - 1] {
                if ratings[i] == ratings[i - 1] {
                    pre = 1;
                } else {
                    pre += 1;
                }
                res += pre;
                inc = pre;
                dec = 0;
            } else {
                // 在严格单调递减时，最少需要的糖果数量是递减次数，但当递减次数正好等于之间严格递增区间长度时，由于最末尾也可以划归到递减区间长度中
                //，导致在递减次数等于前面严格递增长度时，此位置糖果会被分配到递减区间长度+1的糖果，效果上就是desc额外+1
                dec += 1;
                if dec == inc {
                    dec += 1;
                }
                res += dec;
                // 更新当前的递增区间长,但是不能动inc
                pre = 1;
            }
        }
        res
    }
}
// @lc code=end
