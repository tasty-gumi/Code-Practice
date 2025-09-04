#include <bits/stdc++.h>
using namespace std;

struct Node {
  array<int, 26> mn{};
  Node() { mn.fill(0); }
  explicit Node(char c) {
    mn.fill(0);
    mn[c - 'a'] = 1;
  }
};

/* 把两个 minCnt 向量相加（用于串联） */
static Node add(const Node &a, const Node &b) {
  Node r;
  for (int i = 0; i < 26; ++i)
    r.mn[i] = a.mn[i] + b.mn[i];
  return r;
}
/* 取逐字母最小值（用于 {alt1|alt2|…}） */
static Node compMin(const vector<Node> &v) {
  Node r;
  r.mn.fill(INT_MAX / 2);
  for (const Node &n : v)
    for (int i = 0; i < 26; ++i)
      r.mn[i] = min(r.mn[i], n.mn[i]);
  return r;
}

/* ---------- 递归下降解析 ---------- */
string s;    // 输入原串
int pos = 0; // 当前游标

/* 跳过空格、冒号等无关字符 */
static void skipDelim() {
  while (pos < (int)s.size() && (s[pos] == ' ' || s[pos] == ':'))
    ++pos;
}

/* 解析一个串联序列，直到遇到 endCh / '|' / 末尾 */
static Node parseSeq(char endCh) {
  Node cur; // 当前累计结果
  while (pos < (int)s.size()) {
    skipDelim();
    if (pos >= s.size() || s[pos] == endCh || s[pos] == '|')
      break;

    char ch = s[pos];
    Node part;
    if (ch == '[' || ch == '{') { // 子组
      bool optional = (ch == '[');
      ++pos; // 跳过 '['或'{'
      vector<Node> alts;
      while (true) {
        Node seq = parseSeq(ch == '[' ? ']' : '}'); // 读到 ']'或'}'
        alts.push_back(seq);
        if (pos < s.size() && s[pos] == '|') {
          ++pos;
          continue;
        } else
          break; // ] 或 } 将在外层处理
      }
      ++pos; // 跳过 ] 或 }

      if (alts.size() == 1) { // 无 ‘|’
        part = alts[0];
      } else { // 有 ‘|’
        part = compMin(alts);
      }

      if (optional) { // 可选 (单/多) 都可直接变 0 向量
        part.mn.fill(0);
      }
      // 必选 (单/多) ：part 保留计算结果
    } else if (islower(ch)) { // 单个关键字
      part = Node(ch);
      ++pos;
    } else { // 其它符号直接跳过
      ++pos;
      continue;
    }
    cur = add(cur, part); // 串联
  }
  return cur;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  getline(cin, s);

  pos = 0;
  Node root = parseSeq('\0'); // 整条命令
  /* 统计必现关键字 */
  string letters, counts;
  for (int i = 0; i < 26; ++i) {
    if (root.mn[i] > 0) {
      letters.push_back('a' + i);
      counts += to_string(root.mn[i]);
    }
  }
  cout << letters << '\n' << counts << '\n';
  return 0;
}