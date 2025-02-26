/*
 * @lc app=leetcode.cn id=295 lang=rust
 *
 * [295] 数据流的中位数
 */

// @lc code=start
use std::collections::BinaryHeap;
use::std::cmp::Reverse;
struct MedianFinder {
    left :BinaryHeap<i32>, //大根堆
    right :BinaryHeap<Reverse<i32>>, //小根堆 
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MedianFinder {

    fn new() -> Self {
        MedianFinder{
            left : BinaryHeap::new(),
            right : BinaryHeap::new(),
        }
    }
    
    fn add_num(&mut self, num: i32) {
        if !self.left.peek().is_some(){
            self.left.push(num);
        }else{
            if num <= *self.left.peek().unwrap(){    
                self.left.push(num);
            }else{
                self.right.push(Reverse(num));
            }
        }
        // 平衡左右根堆，使得左边的大根堆元素数量始终等于右边小根堆，或者始终仅仅比右边多一个元素
        match self.left.len() as i32 - self.right.len() as i32 {
            -1 =>{
                let Reverse(e) = self.right.pop().unwrap();
                self.left.push(e);
            },
            2 =>{
                let e = self.left.pop().unwrap();
                self.right.push(Reverse(e));
            },
            _ => {},
        }
    }
    
    fn find_median(&self) -> f64 {
        if self.left.peek().is_none(){
            return 0.0;
        }
        let l = self.left.peek().unwrap();
        if self.left.len() == self.right.len(){
            let Reverse(r) = self.right.peek().unwrap();
            (l+r) as f64 / 2.0
        }else{
            *l as f64
        }
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * let obj = MedianFinder::new();
 * obj.add_num(num);
 * let ret_2: f64 = obj.find_median();
 */
// @lc code=end

