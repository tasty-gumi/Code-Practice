/*
 * @lc app=leetcode.cn id=134 lang=rust
 *
 * [134] 加油站
 */

// @lc code=start
// 初步思考本题具有环状性质，且起点答案唯一
// 使用双指针，前向(顺时针)指针代表了从[0,forward]的汽油净增量，而后向(逆时针)指针向后移动是为了弥补净增量让它始终大于等于0
// 判断最终二指针重合的点
impl Solution {
    pub fn can_complete_circuit(gas: Vec<i32>, cost: Vec<i32>) -> i32 {
        let mut remain: i32 = 0;
        let mut forward: i32 = -1;
        let mut back: i32 = gas.len() as i32;
        //这里确保前向指针可以向前挪动
        while forward < gas.len() as i32 - 1 {
            //前项挪动一次并记录净增量
            forward += 1;
            remain += (gas[forward as usize] - cost[forward as usize]);
            // 前后向指针重合，若当期净汽油量足够，则当前位置就是起始位置
            if forward == back && remain >= 0 {
                return back % gas.len() as i32; // 保证不越界
            }
            while remain < 0 {
                back -= 1;
                if back == forward {
                    // 当前这一步被前项指针走过了，说明现在无法弥补，没有解
                    return -1;
                }
                remain += (gas[back as usize] - cost[back as usize]);
            }
        }
        0
    }
}
// @lc code=end
