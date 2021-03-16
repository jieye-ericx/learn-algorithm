// 给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
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
/* 
1  2  3  4
12 13 14 5
11 16 15 6
10 9  8  7
 */
class Solution
{
public:
  vector<vector<int>> generateMatrix(int n)
  {
    int dir = 0; //0向右，1向下，2向左，3向上
    vector<vector<int>> ans(n, vector<int>(n, 0));
    vector<vector<int>> vis(n, vector<int>(n, 0));
    int i = 0, j = 0, cnt = 1;
    while (1)
    {
      while (i < n && j < n && i >= 0 && j >= 0 && vis[i][j] != 1)
      {
        cout << "123: " << i << " " << j << " " << endl;
        ;
        vis[i][j] = 1;
        switch (dir)
        {
        case 0:
          ans[i][j++] = cnt++;
          break;
        case 1:
          ans[i++][j] = cnt++;
          break;
        case 2:
          ans[i][j--] = cnt++;
          break;
        case 3:
          ans[i--][j] = cnt++;
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
      if (i >= n || j >= n || j < 0 || i < 0 || vis[i][j])
      {
        return ans;
      }

      dir = (dir + 1) % 4;
    }
  }
};