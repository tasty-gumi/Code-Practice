/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */

// @lc code=start
#include <list>
#include <unordered_map>
struct Node {
  int key, val, freq;
  Node(int key_, int val_, int freq_) : key(key_), val(val_), freq(freq_) {};
};
class LFUCache {
public:
  LFUCache(int capacity) : capacity_(capacity), min_freq_(0) {}

  int get(int key) {
    auto it = key2node_.find(key);
    if (it == key2node_.end()) {
      return -1;
    }
    auto node = it->second;
    int freq = node->freq;
    int val = node->val;
    freq2list_[freq].erase(node);
    if (freq2list_[freq].empty()) {
      freq2list_.erase(freq);
      if (min_freq_ == freq) {
        min_freq_++;
      }
    }
    ++freq;
    freq2list_[freq].push_front(Node(key, val, freq));
    key2node_[key] = freq2list_[freq].begin();
    return val;
  }

  void put(int key, int value) {
    auto it = key2node_.find(key);
    if (it != key2node_.end()) {
      auto node = it->second;
      int freq = node->freq;
      freq2list_[freq].erase(node);
      if (freq2list_[freq].empty()) {
        freq2list_.erase(freq);
        if (min_freq_ == freq) {
          min_freq_++;
        }
      }
      freq++;
      freq2list_[freq].push_front(Node(key, value, freq));
      key2node_[key] = freq2list_[freq].begin();
    } else {
      if (key2node_.size() != capacity_) {
        min_freq_ = 1;
        freq2list_[1].push_front(Node(key, value, 1));
        key2node_[key] = freq2list_[1].begin();
      } else {
        auto it = freq2list_[min_freq_].back();
        key2node_.erase(it.key);
        freq2list_[min_freq_].pop_back();
        if (freq2list_[min_freq_].empty()) {
          freq2list_.erase(min_freq_);
        }
        min_freq_ = 1;
        freq2list_[1].push_front(Node(key, value, 1));
        key2node_[key] = freq2list_[1].begin();
      }
    }
  }

private:
  int capacity_;
  int min_freq_;
  std::unordered_map<int, std::list<Node>> freq2list_;
  std::unordered_map<int, std::list<Node>::iterator> key2node_;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
