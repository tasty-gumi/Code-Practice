#include <bits/stdc++.h>
using namespace std;

/* ---------- 工具函数 ---------- */
static inline string trim(string s) // 去首尾空格
{
  size_t l = s.find_first_not_of(" \t\r\n");
  size_t r = s.find_last_not_of(" \t\r\n");
  return (l == string::npos) ? "" : s.substr(l, r - l + 1);
}

/* 把 "1-10,15,20-25" 解析成区间向量 */
vector<pair<int, int>> parseRanges(const string &str) {
  vector<pair<int, int>> res;
  string token;
  stringstream ss(str);
  while (getline(ss, token, ',')) {
    token = trim(token);
    if (token.empty())
      continue;
    size_t pos = token.find('-');
    int l, r;
    if (pos == string::npos) { // 单点
      l = r = stoi(token);
    } else { // a-b
      l = stoi(token.substr(0, pos));
      r = stoi(token.substr(pos + 1));
      if (l > r)
        swap(l, r);
    }
    res.emplace_back(l, r);
  }
  return res;
}

/* 区间合并：保持升序、互不重叠、且相邻也要合并 */
void mergeRanges(vector<pair<int, int>> &v) {
  if (v.empty())
    return;
  sort(v.begin(), v.end());
  vector<pair<int, int>> res;
  res.push_back(v[0]);
  for (size_t i = 1; i < v.size(); ++i) {
    auto &cur = v[i];
    auto &back = res.back();
    if (cur.first <= back.second + 1) { // 相交/相邻
      back.second = max(back.second, cur.second);
    } else {
      res.push_back(cur);
    }
  }
  v.swap(res);
}

/* 并操作：把 add 中的所有区间并入 db */
void addRanges(vector<pair<int, int>> &db, const vector<pair<int, int>> &add) {
  db.insert(db.end(), add.begin(), add.end());
  mergeRanges(db);
}

/* 差操作：从 db 中删除 del 的所有区间 */
void removeRanges(vector<pair<int, int>> &db,
                  const vector<pair<int, int>> &del) {
  vector<pair<int, int>> out;
  for (auto seg : db) { // 依次处理数据库里的每个区间
    vector<pair<int, int>> fragments = {seg};
    for (auto rem : del) { // 依次用 del 去裁剪
      vector<pair<int, int>> nxt;
      for (auto part : fragments) {
        if (rem.second < part.first || rem.first > part.second) {
          nxt.push_back(part); // 无交集
        } else {
          if (rem.first > part.first) // 保留左残片
            nxt.emplace_back(part.first, rem.first - 1);
          if (rem.second < part.second) // 保留右残片
            nxt.emplace_back(rem.second + 1, part.second);
        }
      }
      fragments.swap(nxt);
      if (fragments.empty())
        break;
    }
    out.insert(out.end(), fragments.begin(), fragments.end());
  }
  mergeRanges(out); // 再合并一次以去掉可能相邻的小段
  db.swap(out);
}

/* 输出为题目格式 */
string dumpRanges(const vector<pair<int, int>> &v) {
  if (v.empty())
    return "0";
  string res;
  for (size_t i = 0; i < v.size(); ++i) {
    if (i)
      res.push_back(',');
    if (v[i].first == v[i].second)
      res += to_string(v[i].first);
    else
      res += to_string(v[i].first) + "-" + to_string(v[i].second);
  }
  return res;
}

/* ---------- 主程序 ---------- */
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  if (!(cin >> n))
    return 0;
  string dummy;
  getline(cin, dummy); // 吃掉行尾换行

  vector<pair<int, int>> db; // 当前数据库

  for (int i = 0; i < n; ++i) {
    string line;
    getline(cin, line);
    line = trim(line);

    bool isUndo = false;
    if (line.rfind("undo", 0) == 0) { // 行首是 "undo"
      isUndo = true;
      line = trim(line.substr(4)); // 去掉 "undo"
    }

    size_t pos = line.find("algorithm");
    if (pos == string::npos)
      continue;                                   // 格式兜底
    string rangestr = trim(line.substr(pos + 9)); // 跳过 "algorithm"

    vector<pair<int, int>> ranges = parseRanges(rangestr);
    if (isUndo)
      removeRanges(db, ranges);
    else
      addRanges(db, ranges);
  }

  cout << dumpRanges(db) << '\n';
  return 0;
}