/*
 * @lc app=leetcode.cn id=122 lang=rust
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        // // 我个人的实现，dp.0表示当前结束时持有股票的最大利润，dp.1表示当天结束时不持有股票的最大利润
        // let mut max_profit = 0;
        // let mut dp: (i32, i32) = (-prices[0], 0);
        // for i in 1..prices.len() {
        //     dp = (dp.0.max(dp.1 - prices[i]), (dp.0 + prices[i]).max(dp.1));
        //     max_profit = max_profit.max(dp.0).max(dp.1);
        // }
        // max_profit

        // 参考一个内存消耗更少的实现
        // windows方法每次会返回借用两个元素的切片的迭代器，每次next()像下走1个元素
        prices.windows(2).map(|x| i32::max(0, x[1] - x[0])).sum()
    }
}
// @lc code=end
