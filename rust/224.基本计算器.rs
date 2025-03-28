/*
 * @lc app=leetcode.cn id=224 lang=rust
 *
 * [224] 基本计算器
 */

// @lc code=start
impl Solution {
    // 逻辑上和官方解答是一样的，但是会超时
    pub fn calculate(s: String) -> i32 {
        let mut res = 0;
        let mut ops: Vec<i32> = vec![1]; //表示多个用()的多表达式的符号栈
        let mut sign = 1; //取值是{+1，-1}，表示当前表达式的符号
        let mut i: usize = 0;
        while i < s.len() {
            match s.chars().nth(i).unwrap() {
                ' ' => {
                    i += 1;
                    continue;
                }
                '+' => {
                    i += 1;
                    sign = *ops.last().unwrap();
                }
                '-' => {
                    i += 1;
                    sign = -(*ops.last().unwrap());
                }
                '(' => {
                    i += 1;
                    ops.push(sign);
                }
                ')' => {
                    i += 1;
                    let _ = ops.pop();
                }
                _ => {
                    let number_str: String =
                        s.chars().skip(i).take_while(|c| c.is_digit(10)).collect();
                    i += number_str.len();
                    let mut delta: i32 = number_str.parse::<i32>().unwrap();
                    res += sign * delta;
                }
            }
        }
        res
    }
}
// @lc code=end
