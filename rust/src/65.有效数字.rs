use std::f64::consts::E;

/*
 * @lc app=leetcode.cn id=65 lang=rust
 *
 * [65] 有效数字
 */
pub struct Solution;
// @lc code=start
impl Solution {
    pub fn is_number(s: String) -> bool {
        let mut op_wait_num = false; // 标识一下可选符号的出现
        let mut dot_once = false;
        let mut e_wait_interger = false; //标识一下可选指数的出现
        let mut dot_wait_num = false; //标识一下.前面是否出现了数字,如果没有,则是需要
        let len = s.len();
        for (i, ch) in s.chars().enumerate() {
            match ch {
                'e' | 'E' => {
                    if e_wait_interger || dot_wait_num || op_wait_num || i == 0 || i == len - 1 {
                        //唯一一个可选指数,也就是说如果出现多个e也是非有效数字
                        return false;
                    }
                    e_wait_interger = true;
                }
                '+' | '-' => {
                    if dot_wait_num || (i != 0 && s.as_bytes()[i - 1].to_ascii_lowercase() != b'e')
                    {
                        return false;
                    }
                    op_wait_num = true;
                }
                '.' => {
                    if e_wait_interger || dot_once {
                        // .号连续出现或者出现在指数后面
                        return false;
                    }
                    if i == 0 || !s.as_bytes()[i - 1].is_ascii_digit() {
                        //.号前面不出现数位时,在.号后面必定需要数位
                        dot_wait_num = true;
                    }
                    dot_once = true; //已经出现了.号
                    op_wait_num = false; //符号等到了一个十进制数
                }
                '0'..='9' => {
                    op_wait_num = false; //符号等到了一个十进制数或者整数
                    dot_wait_num = false; //.号等到了一个数位
                }
                _ => {
                    return false;
                }
            }
        }
        !op_wait_num && !dot_wait_num
    }
}
// @lc code=end
