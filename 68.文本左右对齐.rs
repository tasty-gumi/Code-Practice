/*
 * @lc app=leetcode.cn id=68 lang=rust
 *
 * [68] 文本左右对齐
 */

// @lc code=start
impl Solution {

    // 返回长度为n的由空格组成的字符串
    pub fn blank(n: usize) ->String {
        " ".repeat(n)
    }

    // 返回 用sep拼接words在[left,right)范围的单词的结果
    pub fn join(words :&[String],left: usize,right: usize,sep :&str) -> String {
        let mut s = words[left].clone();
        for i in left+1..right{
            s.push_str(sep);
            s.push_str(&words[i]);
        }
        s
    }

    pub fn full_justify(words: Vec<String>, max_width: i32) -> Vec<String> {
        let mut jst_res = vec![];
        let mut right: usize = 0;
        let n = words.len();

        loop{
            let left = right;//每次先将当前行的第一个单词初始化好
            let mut sum_len: usize = 0; //当前行的长度和
            // 确定当前需要拼接单词的范围
            while right < n && sum_len + words[right].len()  + right -left <= max_width as usize{
                sum_len += words[right].len() ;  
                right += 1;
            }
            let num_words = right - left; // 要join多少个单词
            let blanks = max_width as usize - sum_len;  // 总空格数

            // 当前是在拼接最后一行
            if right == n {
                let s = Self::join(&words,left,right," "); // 用单空格拼接最后一行的所有单词
                let backblank = blanks - (right-left-1); // 将剩余的空格全部填充到末尾
                jst_res.push(s + &Self::blank(backblank));
                return jst_res;
            }

            //当前行只有一个单词，则左对齐
            if num_words == 1{  
                let s = &words[left];
                jst_res.push(s.clone() + &Self::blank(blanks));
                continue;
            }

            let more_blank_n = blanks % (num_words-1) + 1; // 左边n个需要以多于平均空格数拼接的单词个数
            let avg_blank = blanks/(num_words-1); // 平均的空格数量
            // 以多数空格连接左边的单词
            let l = Self::join(&words,left,left+more_blank_n,&Self::blank(avg_blank+1));
            // 以少数空格连接右边的单词
            let r = Self::join(&words,left+more_blank_n,right,&Self::blank(avg_blank));
            // 拼接起完整的一行
            jst_res.push(l + &Self::blank(avg_blank) + &r);
        }
    }
}
// @lc code=end

