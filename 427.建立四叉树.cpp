/*
 * @lc app=leetcode.cn id=427 lang=cpp
 *
 * [427] 建立四叉树
 */

// @lc code=start
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node*
_bottomLeft, Node* _bottomRight) { val = _val; isLeaf = _isLeaf; topLeft =
_topLeft; topRight = _topRight; bottomLeft = _bottomLeft; bottomRight =
_bottomRight;
    }
};
*/
using namespace std;
class Solution {
public:
  Node *construct_node(int min_row, int max_row, int min_col, int max_col) {
    if (max_row - min_row == 1) {
      return new Node(grid_[min_row][min_col] == 1, true);
    }
    int pre = -1;
    for (int i = min_row; i < max_row; ++i) {
      for (int j = min_col; j < max_col; ++j) {
        if (pre == -1) {
          pre = grid_[i][j];
        } else {
          if (pre != grid_[i][j]) {
            return new Node(
                false, false,
                construct_node(min_row, min_row + (max_row - min_row) / 2,
                               min_col, min_col + (max_col - min_col) / 2),
                construct_node(min_row, min_row + (max_row - min_row) / 2,
                               min_col + (max_col - min_col) / 2, max_col),
                construct_node(min_row + (max_row - min_row) / 2, max_row,
                               min_col, min_col + (max_col - min_col) / 2),
                construct_node(min_row + (max_row - min_row) / 2, max_row,
                               min_col + (max_col - min_col) / 2, max_col));
          }
        }
      }
    }
    return new Node(pre == 1, true);
  }
  Node *construct(vector<vector<int>> &grid) {
    grid_.swap(grid);
    return construct_node(0, grid_.size(), 0, grid_[0].size());
  }

private:
  vector<vector<int>> grid_;
};
// @lc code=end
