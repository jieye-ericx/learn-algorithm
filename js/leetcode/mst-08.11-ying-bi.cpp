/*
硬币。给定数量不限的硬币，币值为25分、10分、5分和1分，
编写代码计算n分有几种表示法。(结果可能会很大，你需要将结果模上1000000007)

示例1:
    输入: n = 5
    输出：2
    解释: 有两种方式可以凑成总金额:
    5=5
    5=1+1+1+1+1
示例2:
    输入: n = 10
    输出：4
    解释: 有四种方式可以凑成总金额:
    10=10
    10=5+5
    10=5+1+1+1+1+1
    10=1+1+1+1+1+1+1+1+1+1
说明：
    注意:
    你可以假设：
        0 <= n (总金额) <= 1000000
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
int combinationSum(vector<int> &candidates, int target);
int correctcombinationSum(vector<int> &candidates, int target);
int main()
{
    vector<int> a;
    int num, t, tar;
    // cin >> num >> tar;
    // while (num--)
    // {
    //     cin >> t;
    //     a.push_back(t);
    // }
    cin >> tar;
    a.push_back(1);
    a.push_back(5);
    a.push_back(10);
    a.push_back(25);
    correctcombinationSum(a, tar);
    // combinationSum(a, tar);
    return 0;
}
// 根据题解的方法
int correctcombinationSum(vector<int> &candidates, int target)
{
    // 1.
    // dp[i][v]表示前i种硬币组成v面值的可能数，很明显，
    // dp[i][v]=求和dp[i-1][v-candidates[i]*(0~k)]
    // 即如果不选第i个面值，则为dp[i-1][v],然后选一个第i种面值，选两个、3个。。。直到最大值k,k=v/candidates[i]
    // 这种最复杂的写法的初值我还没有发现怎么赋值，下面直接简化
    // 2.
    // 简化后dp[i][v]=dp[i-1][v]+dp[i][v-c[i]]
    // 即原本是ff(i,v)=f(i−1,v)+【f(i−1,v−c[i])+f(i−1,v−2c[i])⋯f(i−1,v−kc[i])】
    // 由于v=v-c[i]时，f(i,v−c[i])=【f(i−1,v−c[i])+f(i−1,v−2c[i])+f(i−1,v−3c[i])⋯f(i−1,v−kc[i])】
    // 所以两对【】中的东西相同，可以替换，少了一层循环。
    // 根据64行的公式可以得出二重循环的写法，再优化空间复杂度则可以使用一维数组

    int dp[target + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 0; i < candidates.size(); i++)
    {
        for (int j = candidates[i]; j <= target; j++)
        {
            // 这里我想让下标从1开始，所以用i+1
            dp[j] = dp[j] + dp[j - candidates[i]];
            // cout << "dp[" << i + 1 << "][" << j << "]+=dp[" << i << "][" << j - k * candidates[i] << "]\n";
        }
    }
    cout << dp[target];
    return 1;
}
// 自己写的失败方法
int combinationSum(vector<int> &candidates, int target)
{
    int dp[target + 1];
    memset(dp, 0, sizeof(dp));
    sort(candidates.begin(), candidates.end());
    for (int i = 0; i < candidates.size() && candidates[i] <= target; i++)
    {
        dp[candidates[i]] = 1;
    }
    /*
    我发现这种题动态规划好像做不出所有的解，只能得出是否存在解或者解的数量
    目前主要需要提升动态规划能力，所以这里尝试先算出数量
    用一个一位数组dp，dp[x]表示在目标为x时的解的数量
    那么dp[x]应该为dp[x-candidates[0~size-1]]的和
    enmm,这个方法理想很丰满，但是如果遇到如2+3=5（2和3都为硬币的面值）
    则会重复，所以不行（即出现2+3和3+2两种情况）
    */
    for (int j = 1; j <= target; j++)
    {
        for (int i = 0; i < candidates.size(); i++)
        {
            // for (int k = 0; k * candidates[i] <= j; k++)
            // {
            //     dp[i + 1][j] = max(dp[i - 1][j], dp[i - 1][j - k * candidates[i]] + k * candidates[i]);
            // }
            if (j >= candidates[i])
                dp[j] += dp[j - candidates[i]];
            else
            {
                break;
            }
        }
    }
    for (int i = 1; i < target + 1; i++)
    {
        cout << dp[i] << " ";
    }

    return 1;
}