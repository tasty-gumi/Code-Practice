#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
constexpr unsigned long long mod = 1e9 + 7;

int main() {
  unsigned long n, a, b, c;
  // a,b,c互异
  cin >> n >> a >> b >> c;
  vector<vector<unsigned long long>> methods(n + 1,
                                             vector<unsigned long long>(3, 0));
  methods[a][0] = 1;
  methods[b][1] = 1;
  methods[c][2] = 1;
  for (unsigned long len = 1; len <= n; ++len) {
    unsigned long len_a = len + a;
    unsigned long len_b = len + b;
    unsigned long len_c = len + c;
    // 保证有某种方法能够构成当前长度
    if (methods[len][0] || methods[len][1] || methods[len][2]) {
      if (len_a <= n)
        methods[len_a][0] +=
            (methods[len][0] + methods[len][1] + methods[len][2]) % mod;
      if (len_b <= n)
        methods[len_b][1] +=
            (methods[len][0] + methods[len][1] + methods[len][2]) % mod;
      if (len_c <= n)
        methods[len_c][2] += (methods[len][1] + methods[len][2]) % mod;
    }
    cout << (methods[len][0] + methods[len][1] + methods[len][2]) % mod << endl;
  }
  return 0;
}