#include <iostream>
#include <utility>
#include <vector>

using namespace std;

// 实现一个堆排序，不需要使用额外空间复杂度
void max_heapify(vector<int> &res, int pos, int len) {
  while (pos < len) {
    int left = pos * 2 + 1;
    if (left >= len) {
      return;
    }
    int max = pos;
    int right = pos * 2 + 2;
    if (res[max] < res[left]) {
      max = left;
    }
    if (right < len && res[max] < res[right]) {
      max = right;
    }
    if (max != pos) {
      swap(res[pos], res[max]);
      pos = max;
    } else {
      break;
    }
  }
}

void build_max_heap(vector<int> &res, int n) {
  for (int i = (n - 1) / 2; i >= 0; --i) {
    max_heapify(res, i, n);
  }
}

void heap_sort(vector<int> &res) {
  int n = res.size();
  build_max_heap(res, n);
  for (int i = n - 1; i > 0; --i) {
    swap(res[0], res[i]);
    max_heapify(res, 0, i);
  }
}

int main() {
  vector<int> arr = {34, 43, 2, 31, 46, 44, 1, 34, 23};
  heap_sort(arr);
  for (auto &x : arr) {
    cout << x << ",";
  }
  cout << endl;
  return 0;
}