/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 *
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (44.30%)
 * Likes:    893
 * Dislikes: 0
 * Total Accepted:    174.7K
 * Total Submissions: 393.6K
 * Testcase Example:  '2\n[2,4,1]'
 *
 * 给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。
 *
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
 *
 * 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：k = 2, prices = [2,4,1]
 * 输出：2
 * 解释：在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
 *
 * 示例 2：
 *
 *
 * 输入：k = 2, prices = [3,2,6,5,0,3]
 * 输出：7
 * 解释：在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
 * ⁠    随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 =
 * 3 。
 *
 *
 *
 * 提示：
 *
 *
 * 0
 * 0
 * 0
 *
 *
 */

// @lc code=start
// ? 对于dp数组，若像时机2那样用dp[i][0] 表示在第i天不持有股票，dp[i][1] 表示持有。
//? 则还需要解决只能购买两次的问题
//? 第二题问的是无限次购买
/*
!未进行过任何操作；此时收益都是0，可以不考虑
!只进行过一次买操作；buy1
!进行了一次买操作和一次卖操作，即完成了一笔交易；sell1
!在完成了一笔交易的前提下，进行了第二次买操作；buy2
!完成了全部两笔交易。sell2
这几个变量分别记录当前状态的最大变量
!这里问的是两次购买
! 本次问k次购买，可以把上面两次购买进行发散。
buy[1-k]表示进行过i次购买，buy[i]预示着sell[i-1]一定发生了
sell[1-k]表示完成了[i]次交易
 */

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        if (n <= 1 || k <= 0)
            return 0;
        int buy[k + 1], sell[k + 1];
        for (int i = 1; i <= k; i++)
        {
            buy[i] = -prices[0];
        }
        memset(sell, 0, sizeof(sell));
        // 初始化边界条件结束
        for (int i = 1; i < n; i++)
        {
            // j=1时需要单独处理，不然会访问到j=0
            buy[1] = max(buy[1], -prices[i]);
            sell[1] = max(sell[1], buy[1] + prices[i]);
            for (int j = 2; j <= k; j++)
            {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k];
    }
};
// @lc code=end
