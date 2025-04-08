/*
 * @lc app=leetcode.cn id=912 lang=rust
 *
 * [912] 排序数组
 */

// @lc code=start
use rand::Rng;

impl Solution {
    // pub fn partion(nums: &mut Vec<i32>, l: usize, r: usize) -> () {
    //     if l >= r {
    //         return;
    //     }
    //     let mut pos: usize = l;
    //     let mut left: usize = l;
    //     let mut right: usize = r;
    //     while left < right {
    //         //当枢轴的位置和其中一个相等时，挪动另一根指针
    //         if pos == left {
    //             // 使用小于号是因为
    //             while left < right && nums[right] >= nums[pos] {
    //                 right -= 1;
    //             }
    //             if left == right {
    //                 break;
    //             }
    //             // 很方便的交换值的方式，枢轴的值和对应指针交换
    //             (nums[pos], nums[right]) = (nums[right], nums[pos]);
    //             left = pos + 1;
    //             pos = right;
    //         } else {
    //             while left < right && nums[left] <= nums[pos] {
    //                 left += 1;
    //             }
    //             if left == right {
    //                 break;
    //             }
    //             (nums[pos], nums[left]) = (nums[left], nums[pos]);
    //             right = pos - 1;
    //             pos = left;
    //         }
    //     }
    //     // 看枢轴的位置在哪里，有必要的时候再将左边和右边排序
    //     if pos > l + 1 {
    //         Self::partion(nums, l, pos - 1);
    //     }
    //     if pos < r - 1 {
    //         Self::partion(nums, pos + 1, r);
    //     }
    // }
    pub fn partion(nums: &mut Vec<i32>, l: i32, r: i32) -> i32 {
        let mut i: i32 = l - 1;
        let pivot = nums[r as usize];
        for j in l..r {
            if nums[j as usize] <= pivot {
                i += 1;
                (nums[i as usize], nums[j as usize]) = (nums[j as usize], nums[i as usize])
            }
        }
        i + 1
    }
    pub fn quicksort(nums: &mut Vec<i32>, l: i32, r: i32) {
        if l < r {
            let rand_p = rand::thread_rng().gen_range(l..=r);
            (nums[rand_p as usize], nums[r as usize]) = (nums[r as usize], nums[rand_p as usize]);
            let p = Self::partion(nums, l, r);
            (nums[p as usize], nums[r as usize]) = (nums[r as usize], nums[p as usize]);
            Self::quicksort(nums, l, p - 1);
            Self::quicksort(nums, p + 1, r);
        }
    }
    pub fn sort_array(mut nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        Self::quicksort(&mut nums, 0, n as i32 - 1);
        nums
    }
}
// @lc code=end
