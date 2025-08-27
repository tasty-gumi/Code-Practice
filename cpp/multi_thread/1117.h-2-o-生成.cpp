/*
 * @lc app=leetcode.cn id=1117 lang=cpp
 *
 * [1117] H2O 生成
 */
#include <condition_variable>
#include <functional>
#include <mutex>
using namespace std;
// @lc code=start
class H2O {
public:
  H2O() {}

  void hydrogen(function<void()> releaseHydrogen) {

    // releaseHydrogen() outputs "H". Do not change or remove this line.
    unique_lock<mutex> lock(m);
    cv.wait(lock, [this] { return hc < 2; });
    releaseHydrogen();
    ++hc;
    if (oc + hc == 3) {
      oc = 0;
      hc = 0;
    }
    cv.notify_all();
  }

  void oxygen(function<void()> releaseOxygen) {

    // releaseOxygen() outputs "O". Do not change or remove this line.
    unique_lock<mutex> lock(m);
    cv.wait(lock, [this] { return oc == 0; });
    releaseOxygen();
    ++oc;
    if (oc + hc == 3) {
      oc = 0;
      hc = 0;
    }
    cv.notify_all();
  }

private:
  int hc = 0;
  int oc = 0;
  std::mutex m;
  std::condition_variable cv;
};
// @lc code=end
