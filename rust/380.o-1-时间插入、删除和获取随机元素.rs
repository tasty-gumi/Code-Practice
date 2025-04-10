/*
 * @lc app=leetcode.cn id=380 lang=rust
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */

// @lc code=start
//基本思路是使用Hash表提供O(1)判断是否存在，而用Vec使用下标提供随机化访问
use std::collections::HashMap;
use rand::Rng;
struct RandomizedSet {
    map:HashMap<i32,usize>, //元素到数组下标的映射
    elements:Vec<i32>, // 顺序排列元组的数组
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RandomizedSet {

    fn new() -> Self {
        RandomizedSet{
            map :HashMap::new(),
            elements: Vec::new(),
        }
    }
    
    fn insert(&mut self, val: i32) -> bool {
        let inserted = !self.map.contains_key(&val);
        self.map.entry(val).or_insert_with( || { self.elements.push(val);  self.elements.len()-1});
        inserted
    }
    
    fn remove(&mut self, val: i32) -> bool {
        if let Some(idx) = self.map.remove(&val){
            let last = self.elements[self.elements.len()-1];
            //使用最后一个元素覆盖前一个
            self.elements[idx] = last;
            // 弹出要删除的元素
            self.elements.pop();
            //更新最后一个元素的索引
            if last != val{
                self.map.insert(last,idx);
            }
            true
        }else{
            false
        }
    }
    
    fn get_random(&self) -> i32 {
        let roll = rand::thread_rng().gen_range(0..self.elements.len());
        self.elements[roll]
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * let obj = RandomizedSet::new();
 * let ret_1: bool = obj.insert(val);
 * let ret_2: bool = obj.remove(val);
 * let ret_3: i32 = obj.get_random();
 */
// @lc code=end

