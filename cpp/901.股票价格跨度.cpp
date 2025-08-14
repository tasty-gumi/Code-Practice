/*
 * @lc app=leetcode.cn id=901 lang=cpp
 *
 * [901] 股票价格跨度
 */
#include <climits>
#include <stack>
#include <utility>
using namespace std;
// @lc code=start
class StockSpanner {
public:
  StockSpanner() { st.emplace(-1, INT_MAX); }

  int next(int price) {
    while (st.top().second <= price) {
      st.pop();
    }
    int res = day - st.top().first;
    st.emplace(day++, price);
    return res;
  }

private:
  stack<pair<int, int>> st;
  int day = 0;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
// @lc code=end
