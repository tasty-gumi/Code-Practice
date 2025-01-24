/*
 * @lc app=leetcode.cn id=30 lang=rust
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
use std::collections::HashMap;
impl Solution {
        pub fn find_substring(s: String, words: Vec<String>) -> Vec<i32> {
            let s_len = s.len();
            let words_n = words.len();
            let word_len = words[0].len();
            let mut differ: HashMap<String,i32> = HashMap::new();
            let mut res: Vec<i32> = Vec::<i32>::new();
            for word in &words{
                *differ.entry(word.to_string()).or_insert(0) -= 1;
            };
            // 如果每个单词长度是word_len，那么将有word_len躺检测，没一趟按word_len将s划分成单词组
            for i in 0..word_len{
                if i + word_len* words_n > s_len{ //窗口的大小比s都长，不用检测了
                    break;
                }
                // 初始化一个划分组的diff哈希表，表示当前窗口中单词与words中单词之差异，如果哈希表是空，则表明没有差异
                let mut diff = differ.clone();
                for j in 0..words_n{
                    let word = &s[i+j*word_len..i+(j+1)*word_len];
                    let count = diff.entry(word.to_string()).or_insert(0);
                    *count +=1;
                    if *count == 0{
                        diff.remove(word);
                    } 
                }
                // 开始滑动当前窗口检测,每次滑进右边的一个单词，滑出最左边单词
                for start in (i..s_len-word_len*words_n+1).step_by(word_len){ //保证当前窗口是有效的
                    if start != i { // 计算当前相对与上一个窗口的diff改动
                        let coming_word = &s[start+word_len*(words_n-1)..start+word_len*words_n];
                        let c =  diff.entry(coming_word.to_string()).or_insert(0);
                        *c += 1;
                        if *c == 0{
                            diff.remove(coming_word);
                        } 
                        let leave_word = &s[start-word_len..start];
                        let l = diff.entry(leave_word.to_string()).or_insert(0);
                        *l -= 1;
                        if *l == 0{
                            diff.remove(leave_word);
                        }
                    }
                    if diff.is_empty(){
                        res.push(start as i32);    
                    }
                }
            }
            res
        }
}
// @lc code=end

