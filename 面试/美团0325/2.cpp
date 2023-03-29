/***
 *
 *
 *
 *小美因乐于助人的突出表现获得了老师的嘉奖。老师允许小美从一堆n个编号分别为1,2,...,n的糖果中选择任意多个糖果作为奖励（每种编号的糖果各一个），但为了防止小美一次吃太多糖果有害身体健康，老师设定了一个限制：如果选择了编号为 i 的糖果，那么就不能选择编号为 i-1, i-2, i+1, i+2的四个糖果了。在小美看来，每个糖果都有一个对应的美味值，小美想让她选出的糖果的美味值之和最大！作为小美的好朋友，请你帮帮她！
 *样例输入
7
3 1 2 7 10 2 4
样例输出
14

 */

#include <iostream>
#include <vector>
using namespace std;

const int N = 50005;
int arr[N];
vector<vector<int>> dp;

int main()
{
  int n;
  while (cin >> n)
  {

    for (int i = 1; i <= n; ++i)
      cin >> arr[i];
    dp = vector<vector<int>>(n + 1, vector<int>(2, 0));
    dp[1][1] = arr[1];
    for (int i = 2; i <= n; ++i)
    {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
      dp[i][1] = dp[i - 2][0] + arr[i];
    }
    cout << max(dp[n][0], dp[n][1]) << endl;
  }
  return 0;
}