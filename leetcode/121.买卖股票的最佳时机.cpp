#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
int main()
{

  return 0;
}
/* 
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。 */
/* 
输入：[7,1,5,3,6,4]
输出：5
解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。 */
int maxProfit(vector<int> &prices)
{
  int minP = prices[0], ans = 0;
  //!dp[i]表示第i天卖出能获得的最大收入,明显最大收入取决于当天的价格-之前的最小价格

  for (int i = 1; i < prices.size(); i++)
  {
    ans = max(ans, prices[i] - minP);
    minP = min(minP, prices[i]);
  }
  return ans;
}