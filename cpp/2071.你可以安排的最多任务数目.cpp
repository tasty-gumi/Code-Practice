/*
 * @lc app=leetcode.cn id=2071 lang=cpp
 *
 * [2071] 你可以安排的最多任务数目
 */
#include <algorithm>
#include <deque>
#include <functional>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills,
                    int strength) {
    int finish = 0;
    sort(tasks.begin(), tasks.end(), std::less<int>());
    sort(workers.begin(), workers.end(), std::greater<int>());
    // k个最小的任务可以由k个值最大的工人完成，那么k-1个最小的任务也可以由值最大的k-1个工人完成
    // 寻找这样的上界k，则可以使用二分法，当找到1个k’使得满足上述情况时，前k‘-1可以省略
    // 而找到某个k’‘使得不满足上述情况，后k’‘可以省略
    int left = 1;
    int right = std::min(tasks.size(), workers.size());

    auto check = [&](int mid) -> bool {
      int p = pills;
      // 从大到小枚举任务，当前任务能由队列中最大的力量值的工人完成就使用，否则找到一个使用药片的最小的力量的满足条件的工人
      int pos = 0;
      // 使用双端队列的好处在于，可以随时出对最大的或者吃药片最小的
      deque<int> wq;
      for (int i = mid - 1; i >= 0; --i) {
        // 枚举到下一个任务时，队列中的元素也一定满足吃了药片比下一个任务大
        while (pos < mid && workers[pos] + strength >= tasks[i]) {
          wq.push_front(workers[pos]);
          ++pos;
        }
        if (wq.empty()) {
          // 没有能够完成当前任务的worker
          return false;
        } else if (wq.back() >= tasks[i]) {
          // 如果当前队列中最大力量的worker能够不吃药丸完成任务直接出队
          wq.pop_back();
        } else {
          // 需要吃药丸才能完成任务选择最小的worker
          if (p == 0) {
            return false;
          }
          --p;
          wq.pop_front();
        }
      }
      return true;
    };
    int mid;
    while (left <= right) {
      mid = (left + right) / 2;
      if (check(mid)) {
        finish = mid;
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return finish;
  }
};
// @lc code=end
