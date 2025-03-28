/*
 * @lc app=leetcode.cn id=402 lang=golang
 *
 * [402] 移掉 K 位数字
 */

// @lc code=start
func removeKdigits(num string, k int) string {
	stack := []rune{}
	for _,ch := range num {
		for k>0 && len(stack) > 0 && stack[len(stack)-1] > ch{
			stack = stack[0:len(stack)-1]
			k--
		}
		stack = append(stack,ch)
	} 
	if k>0  {
		stack = stack[:len(stack)-k]
	}
	zeroCount := 0
	for _,ch := range stack{
		if  ch == '0'{
			zeroCount++
		}else{
			break
		}
	}
	stack = stack[zeroCount:]
	if len(stack) == 0{
		return "0"
	}
	return string(stack)
}
// @lc code=end

