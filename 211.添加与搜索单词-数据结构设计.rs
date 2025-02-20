/*
 * @lc app=leetcode.cn id=211 lang=rust
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
use::std::collections::HashMap;
struct WordDictionary {
    childs: HashMap<char ,Box<WordDictionary>>,
    is_end: bool ,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl WordDictionary {

    fn new() -> Self {
        WordDictionary {
            childs: HashMap::new(),
            is_end:false ,
        }
    }
    
    fn add_word(&mut self, word: String) {
        let mut node = self;
        for c in word.chars(){
            node = node.childs.entry(c).or_insert_with(|| Box::new(WordDictionary::new()));
        }
        node.is_end = true;
    }
    
    fn search_helper(&self,chars:Vec<char>,index :usize ) ->bool {
        if index == chars.len(){
            return self.is_end
        }
        
        let ch = chars[index];
        if ch == '.'{
            for child in self.childs.values(){
                if child.search_helper(chars.clone(),index+1){
                    return true;
                }
            }
            false
        }else{
           if let Some(child) = self.childs.get(&ch){
             child.search_helper(chars,index+1)
           }else{
            false
           }
        }
    }

    fn search(&self, word: String) -> bool {
        self.search_helper(word.chars().collect(),0)
    }
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * let obj = WordDictionary::new();
 * obj.add_word(word);
 * let ret_2: bool = obj.search(word);
 */
// @lc code=end

