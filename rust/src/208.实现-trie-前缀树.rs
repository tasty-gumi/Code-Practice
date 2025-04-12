/*
 * @lc app=leetcode.cn id=208 lang=rust
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
use::std::collections::HashMap;
struct Trie {
    childs: HashMap<char ,Box<Trie>>,
    is_end: bool ,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Trie {

    fn new() -> Self {
        Trie{
            childs:HashMap::new(),
            is_end:false,
        }
    }
    
    fn insert(&mut self, word: String) {
        let mut node = self;
        for ch in word.chars(){
            node = node.childs.entry(ch).or_insert_with(|| Box::new(Trie::new()));
        }
        node.is_end = true; 
    }
    
    fn search(&self, word: String) -> bool {
        let mut node = self;
        for ch in word.chars(){
            if let Some(child) = node.childs.get(&ch){
                node = child;
            }else{
                return false;
            }
        }
        node.is_end
    }
    
    fn starts_with(&self, prefix: String) -> bool {
        let mut node = self;
        for ch in prefix.chars(){
            if let Some(child) = node.childs.get(&ch){
                node = child;
            }else{
                return false;
            }
        }
        true
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * let obj = Trie::new();
 * obj.insert(word);
 * let ret_2: bool = obj.search(word);
 * let ret_3: bool = obj.starts_with(prefix);
 */
// @lc code=end

