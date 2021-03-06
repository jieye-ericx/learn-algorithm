/* 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 */

/* 
输入：prices = [3,3,5,0,0,3,1,4]
输出：6
解释：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
 */

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
//? 对于dp数组，若像时机2那样用dp[i][0]表示在第i天不持有股票，dp[i][1]表示持有。
//? 则还需要解决只能购买两次的问题
/* 
!未进行过任何操作；此时收益都是0，可以不考虑
!只进行过一次买操作；buy1
!进行了一次买操作和一次卖操作，即完成了一笔交易；sell1
!在完成了一笔交易的前提下，进行了第二次买操作；buy2
!完成了全部两笔交易。sell2
这几个变量分别记录当前状态的最大变量

 */
int maxProfit(vector<int> &prices)
{
  int n = prices.size();
  if (n <= 1)
    return 0;
  int buy1 = -prices[0], buy2 = -prices[0], sell1 = 0, sell2 = 0;
  for (int i = 1; i < n; i++)
  {
    buy1 = max(buy1, -prices[i]);
    //! buy1+prices[i]表示i天卖出获得的收益
    sell1 = max(sell1, buy1 + prices[i]);
    // !第二次购买时需要用第一次的收益减去i天的价格
    buy2 = max(buy2, sell1 - prices[i]);
    sell2 = max(sell2, buy2 + prices[i]);
  }
  return sell2;
}
