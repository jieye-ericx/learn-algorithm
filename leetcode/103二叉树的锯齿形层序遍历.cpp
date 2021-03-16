// https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
#include <map>
#include <list>
using namespace std;
int main()
{

  return 0;
}
class Solution
{
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root)
  {
    vector<vector<int>> a = vector<vector<int>>(0);
    if (!root)
      return a;
    int preNum = 1, nowNum = 0, dir = 1; //0从左到右1从右到左

    TreeNode *tmpPtr;
    vector<int> tmpAns;

    queue<TreeNode *> d;
    d.push(root);
    while (!d.empty())
    {
      tmpPtr = d.front();
      d.pop();
      tmpAns.push_back(tmpPtr->val);
      if (tmpPtr->left)
      {
        d.push(tmpPtr->left);
        nowNum++;
      }
      if (tmpPtr->right)
      {
        d.push(tmpPtr->right);
        nowNum++;
      }

      preNum--;
      if (!preNum)
      {
        preNum = nowNum;
        nowNum = 0;
        if (dir == 1)
        {
          reverse(tmpAns.begin(), tmpAns.end());
        }
        a.push_back(tmpAns);
        dir = (dir + 1) % 2;
        // tmpAns.clear();
        tmpAns = vector<int>(0);
      }
    }
    return a;
  }
};
