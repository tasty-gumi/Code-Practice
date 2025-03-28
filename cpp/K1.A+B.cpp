#include <cstdint>
#include <iostream>
#include <vector>

// 题目描述
// 你的任务是计算若干整数的和。
// 输入描述
// 输入的第一行为一个整数N，接下来N行每行先输入一个整数M，然后在同一行内输入M个整数。

// 输出描述
// 对于每组输入，输出M个数的和，每组输出之间输出一个空行。

// 输入示例
// 3
// 4 1 2 3 4
// 5 1 2 3 4 5
// 3 1 2 3
// 输出示例
// 10

// 15

// 6
using namespace std;
int main() {
  int N;
  while (cin >> N) {
    for (int i = 0; i < N; ++i) {
      if (i != 0) {
        cout << endl;
      }
      int m;
      cin >> m;
      int total = 0;
      for (int j = 0; j < m; ++j) {
        int tmp;
        cin >> tmp;
        total += tmp;
      }
      cout << total << endl;
    }
  }
  return 0;
}