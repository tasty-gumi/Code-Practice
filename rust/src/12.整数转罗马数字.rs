/*
 * @lc app=leetcode.cn id=12 lang=rust
 *
 * [12] 整数转罗马数字
 */
pub struct Solution;
// @lc code=start
impl Solution {
    pub fn int_to_roman(mut num: i32) -> String {
        //基本思想就是构造一个罗马数字表，从千位开始向后构造数字，每次取最高位数字作为判断
        let mut romanstrs: String = String::new();
        let romans: [char; 7] = ['M', 'D', 'C', 'L', 'X', 'V', 'I'];
        let mut count = 0usize;
        while count < 4 {
            let base = 10usize.pow(3u32 - count as u32);
            let cur = num as usize / base;
            match cur {
                0..4 => {
                    for _ in 0..cur {
                        romanstrs.push(romans[2 * count]);
                    }
                }
                4 => {
                    romanstrs.push(romans[2 * count]);
                    romanstrs.push(romans[2 * count - 1]);
                }
                5..9 => {
                    romanstrs.push(romans[2 * count - 1]);
                    for _ in 0..cur - 5 {
                        romanstrs.push(romans[2 * count]);
                    }
                }
                9 => {
                    romanstrs.push(romans[2 * count]);
                    romanstrs.push(romans[2 * count - 2]);
                }
                _ => {
                    panic!("取模操作不会发生异常")
                }
            }
            num -= cur as i32 * base as i32;
            count += 1;
        }
        romanstrs
    }
}
// @lc code=end
