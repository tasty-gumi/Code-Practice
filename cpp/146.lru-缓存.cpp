/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start

#include <iterator>
#include <list>
#include <unordered_map>
class LRUCache {
public:
  LRUCache(int capacity) : cap(capacity) {}

  int get(int key) {
    if (!map.count(key))
      return -1;
    moveToFront(map[key]);
    return map[key]->second;
  }

  void put(int key, int value) {
    if (map.count(key)) {
      map[key]->second = value;
      moveToFront(map[key]);
    } else {
      if (node_list.size() == cap) {
        map.erase(node_list.back().first);
        node_list.pop_back();
      }
      node_list.push_front({key, value});
      map[key] = node_list.begin();
    }
  }

private:
  std::list<std::pair<int, int>> node_list;
  std::unordered_map<int, std::list<std::pair<int, int>>::iterator> map;
  int cap;

  void moveToFront(std::list<std::pair<int, int>>::iterator &it) {
    auto p = *it;
    node_list.erase(it);
    node_list.push_front(p);
    map[p.first] = node_list.begin();
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
