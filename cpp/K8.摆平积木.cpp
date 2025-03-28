#include <iostream>
#include <vector>

using namespace std;
int main() {
  int n;
  while (cin >> n) {
    if (!n)
      break;
    int total = 0;
    int count = 0;
    int tmp;
    vector<int> res;
    for (int i = 0; i < n; ++i) {
      cin >> tmp;
      total += tmp;
      ++count;
      res.emplace_back(tmp);
    }
    int avg = total / count;
    int resn = 0;
    for (auto &x : res) {
      if (x > avg) {
        resn += x - avg;
      }
    }
    cout << resn << endl << endl;
  }

  return 0;
}