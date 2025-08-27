/*
 * @lc app=leetcode.cn id=1116 lang=cpp
 *
 * [1116] 打印零与奇偶数
 */
#include <condition_variable>
#include <functional>
#include <mutex>
using namespace std;
// @lc code=start
class ZeroEvenOdd {
private:
  int n;
  int cur = 1;
  int state = 0;
  std::mutex m;
  std::condition_variable cv;

public:
  ZeroEvenOdd(int n) { this->n = n; }

  // printNumber(x) outputs "x", where x is an integer.
  void zero(function<void(int)> printNumber) {
    while (true) {
      unique_lock<mutex> lock(m);
      cv.wait(lock, [this]() -> bool { return state == 0; });
      if (cur > n)
        break;
      printNumber(0);
      if (cur % 2) {
        state = 1;
      } else {
        state = 2;
      }
      cv.notify_all();
    }
  }

  void even(function<void(int)> printNumber) {
    while (true) {
      unique_lock<mutex> lock(m);
      cv.wait(lock, [this] { return state == 2 || cur > n; });
      if (cur > n)
        break;
      printNumber(cur++);
      state = 0;
      cv.notify_all();
    }
  }

  void odd(function<void(int)> printNumber) {
    while (true) {
      unique_lock<mutex> lock(m);
      cv.wait(lock, [this] { return state == 1 || cur > n; });
      if (cur > n)
        break;
      printNumber(cur++);
      state = 0;
      cv.notify_all();
    }
  }
};
// @lc code=end
