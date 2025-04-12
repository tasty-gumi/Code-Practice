/*
 * @lc app=leetcode.cn id=13 lang=rust
 *
 * [13] 罗马数字转整数
 */
pub struct Solution;
// @lc code=start
impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        //使用peekable()的迭代器，此迭代器每次都可以look at当前迭代器的下一个迭代器，但并不消费掉当前的迭代器
        //比较方便迭代，且不需要额外空间复杂度从s创建chars数组
        // let mut iter = s.chars().peekable();
        // let mut res = 0i32;
        // let mut skip;
        // let mut delta;
        // while let Some(ch) = iter.next() {
        //     (delta, skip) = match (ch, iter.peek()) {
        //         ('I', Some(&'V')) => (4, true),
        //         ('I', Some(&'X')) => (9, true),
        //         ('X', Some(&'L')) => (40, true),
        //         ('X', Some(&'C')) => (90, true),
        //         ('C', Some(&'D')) => (400, true),
        //         ('C', Some(&'M')) => (900, true),
        //         ('I', _) => (1, false),
        //         ('V', _) => (5, false),
        //         ('X', _) => (10, false),
        //         ('L', _) => (50, false),
        //         ('C', _) => (100, false),
        //         ('D', _) => (500, false),
        //         ('M', _) => (1000, false),
        //         _ => panic!("不合法的罗马数字输入!!"),
        //     };
        //     if skip {
        //         iter.next();
        //     }
        //     res += delta;
        // }

        //使用反向迭代器的方法,从小值开始向高位走，这样不用每次都探测peekable，会更方便
        // 这里的经验就是，有Some的match会降低性能
        // 最好不要使用迭代器的next
        // let mut iter = s.chars().rev();
        let mut res = 0i32;
        let mut last = 0i32;
        let mut v;
        for ch in s.chars().rev() {
            v = match ch {
                'I' => 1,
                'V' => 5,
                'X' => 10,
                'L' => 50,
                'C' => 100,
                'D' => 500,
                'M' => 1000,
                _ => panic!("不合法的罗马数字字符"),
            };
            if v < last {
                res -= v;
            } else {
                res += v;
            }
            last = v;
        }
        res
    }
}
// @lc code=end
