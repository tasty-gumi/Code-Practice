/*
 * @lc app=leetcode.cn id=121 lang=rust
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut max_profit: i32 = 0;
        let mut min_price: i32 = i32::MAX;
        for price in prices {
            if price < min_price {
                min_price = price;
            } else {
                max_profit = max_profit.max(price - min_price);
            }
        }
        max_profit
    }
}
// @lc code=end
