#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <cmath>
using namespace std;
int maxSubArray(vector<int> &nums);
// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
// nums = [-2,1,-3,4,-1,2,1,-5,4] 输出：6 解释：连续子数组[4, -1, 2, 1] 的和最大，为 6 。
// ? 设定dp数组，dp[i]表示nums[0-i]的最大和
int main()
{
    vector<int> a(9);
    a[0] = -2;
    a[1] = 1;
    a[2] = -3;
    a[3] = 4;
    a[4] = -1;
    a[5] = 2;
    a[6] = 1;
    a[7] = -5;
    a[8] = 4;
    cout << maxSubArray(a);
    return 0;
}
int maxSubArray(vector<int> &nums)
{
    int dp[nums.size() + 1], ans = nums[0];
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        dp[i] = max(nums[i], nums[i] + dp[i - 1]);
        ans = max(ans, dp[i]);
    }
    return ans;
}