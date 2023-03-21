/**
 * 小美在玩一项游戏。该游戏的目标是尽可能抓获敌人。

敌人的位置将被一个二维坐标 (x, y) 所描述。

小美有一个全屏技能，该技能能一次性将若干敌人一次性捕获。

捕获的敌人之间的横坐标的最大差值不能大于A，纵坐标的最大差值不能大于B。

现在给出所有敌人的坐标，你的任务是计算小美一次性最多能使用技能捕获多少敌人。

输入描述
第一行三个整数N,A,B，表示共有N个敌人，小美的全屏技能的参数A和参数B。

接下来N行，每行两个数字x,y，描述一个敌人所在的坐标。

1≤N≤500，1≤A,B≤1000，1≤x,y≤1000。

输出描述
一行，一个整数表示小美使用技能单次所可以捕获的最多数量。
 * */

// !双指针不太行，参考了大佬的二维前缀和
/**
 * import java.util.Scanner;

public class Main {
    static final int N = 1000;
    static int[][] g = new int[N + 10][N + 10];
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), a = sc.nextInt(), b = sc.nextInt();
        a++; b++; // 最大间隔++，前缀和下标从1开始处理，防止边界问题
        // 与N取min
        a = Math.min(a, N);
        b = Math.min(b, N);
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt(), y = sc.nextInt();
            g[x][y]++; // 读入敌人坐标
        }
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1]; // 二维前缀和预处理 公式一
            }
        }
        int res = 0;
        // 枚举一下所有长宽是ab的矩形，(i,j)为右下角，取max
        for (int i = a; i <= N; i++) {
            for (int j = b; j <= N; j++) {
                res = Math.max(res, g[i][j] - g[i - a][j] - g[i][j - b] + g[i - a][j - b]); // 求某一个子矩阵的值 公式二
            }
        }
        System.out.println(res);
    }
}
 *
*/
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
using namespace std;

int N, A, B, x, y;
vector<vector<int>> arr;
bool cmp(pair<int, int> p1, pair<int, int> p2)
{
  if (p1.first != p2.first)
  {
    return p1.first < p2.first;
  }
  return p1.second < p2.second;
}
int main()
{
  while (cin >> N >> A >> B)
  {
    int ans = 0, le = 0, ri = 0, n = N, tans = 0;
    vector<pair<int, int>> p;
    while (N--)
    {
      cin >> x >> y;
      p.emplace_back(x, y);
    }
    sort(p.begin(), p.end(), cmp);
    for (int i = 0; i < n; i++)
    {
      tans = 0;
      // cout << i << endl;
      for (int j = i; j < n; j++)
      {
        int dx = abs(p[i].first - p[j].first), dy = abs(p[i].second - p[j].second);
        // cout << i << " " << j << " " << dx << " " << dy << endl;
        if (dx <= A && dy <= B)
        {
          tans++;
        }
      }
      ans = max(ans, tans);
    }
    cout << ans << endl;
  }

  return 0;
}

/**
 * 小美在玩一项游戏。该游戏的目标是尽可能抓获敌人。

敌人的位置将被一个二维坐标 (x, y) 所描述。

小美有一个全屏技能，该技能能一次性将若干敌人一次性捕获。

捕获的敌人之间的横坐标的最大差值不能大于A，纵坐标的最大差值不能大于B。

现在给出所有敌人的坐标，你的任务是计算小美一次性最多能使用技能捕获多少敌人。

输入描述
第一行三个整数N,A,B，表示共有N个敌人，小美的全屏技能的参数A和参数B。

接下来N行，每行两个数字x,y，描述一个敌人所在的坐标。

1≤N≤500，1≤A,B≤1000，1≤x,y≤1000。

输出描述
一行，一个整数表示小美使用技能单次所可以捕获的最多数量。
 * */

#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
using namespace std;

int N, A, B, x, y;
vector<vector<int>> arr;
bool cmp(pair<int, int> p1, pair<int, int> p2)
{
  if (p1.first != p2.first)
  {
    return p1.first < p2.first;
  }
  return p1.second < p2.second;
}
int main()
{
  while (cin >> N >> A >> B)
  {
    int ans = 0, le = 0, ri = 0, n = N;
    vector<pair<int, int>> p(N);
    while (n--)
    {
      cin >> x >> y;
      p.emplace_back(x, y);
    }
    sort(p.begin(), p.end(), cmp);
    while (ri < N)
    {
      // cout << le << " " << ri << endl;
      while (p[ri].first - p[le].first > B || p[ri].second - p[le].second > A)
      {
        // cout << le << " " << ri << " " << num << endl;
        le++;
      }
      ri++;
      int num = ri - le;
      while (ri < N && p[ri].first - p[le].first <= B && p[ri].second - p[le].second <= A)
      {
        // cout << " sad" << N << endl;
        // cout << le << " " << ri << endl;
        ans = max(ans, ri - le);
        ri++;
        // num++;
      }
      // ans = max(ans, num);
      ri++;
    }
    cout << ans << endl;
  }

  return 0;
}
