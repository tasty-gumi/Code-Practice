/*
 * @lc app=leetcode.cn id=1114 lang=cpp
 *
 * [1114] 按序打印
 */
#include <functional>
#include <mutex>
// @lc code=start
class Foo {
private:
  std::mutex m2, m3; // 用于控制second和third的执行时机

public:
  Foo() {
    // 初始时锁定m2和m3，确保second和third必须等待
    m2.lock();
    m3.lock();
  }

  void first(std::function<void()> printFirst) {
    printFirst(); // 首先执行first
    m2.unlock();  // 解锁m2，允许second执行
  }

  void second(std::function<void()> printSecond) {
    std::lock_guard<std::mutex> lock(m2); // 等待m2解锁
    printSecond();                        // 执行second
    m3.unlock();                          // 解锁m3，允许third执行
  }

  void third(std::function<void()> printThird) {
    std::lock_guard<std::mutex> lock(m3); // 等待m3解锁
    printThird();                         // 执行third
  }
};
// @lc code=end
