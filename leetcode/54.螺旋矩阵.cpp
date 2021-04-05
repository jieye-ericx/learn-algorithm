// 给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。
/* 输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5] 
输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]*/
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
  vector<int> spiralOrder(vector<vector<int>> &matrix)
  {
    int dir = 0; //0向右，1向下，2向左，3向上
    int m = matrix.size(), n = matrix[0].size();
    vector<int> ans;
    vector<vector<int>> vis(m, vector<int>(n, 0));
    int i = 0, j = 0;
    while (1)
    {
      while (i < m && j < n && i >= 0 && j >= 0 && vis[i][j] != 1)
      {
        cout << "123: " << i << " " << j << " " << m << " " << n << endl;
        ;
        vis[i][j] = 1;
        switch (dir)
        {
        case 0:
          ans.emplace_back(matrix[i][j++]);
          break;
        case 1:
          ans.emplace_back(matrix[i++][j]);
          break;
        case 2:
          ans.emplace_back(matrix[i][j--]);
          break;
        case 3:
          ans.emplace_back(matrix[i--][j]);
          break;
        }
      }
      // 第一次结束时i=0,j=n;
      switch (dir)
      {
      case 0:
        i++, j--;
        break;
      case 1:
        i--, j--;
        break;
      case 2:
        i--, j++;
        break;
      case 3:
        i++, j++;
        break;
      }
      cout << i << " " << j << " " << m << " " << n;
      if (i >= m || j >= n || j < 0 || i < 0 || vis[i][j])
      {
        cout << "sadasd";
        return ans;
      }

      dir = (dir + 1) % 4;
    }
  }
};