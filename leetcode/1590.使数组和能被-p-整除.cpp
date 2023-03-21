/*
 * @lc app=leetcode.cn id=1590 lang=cpp
 *
 * [1590] 使数组和能被 P 整除
 *
 * https://leetcode.cn/problems/make-sum-divisible-by-p/description/
 *
 * algorithms
 * Medium (28.87%)
 * Likes:    129
 * Dislikes: 0
 * Total Accepted:    13.2K
 * Total Submissions: 39.8K
 * Testcase Example:  '[3,1,4,2]\n6'
 *
 * 给你一个正整数数组 nums，请你移除 最短 子数组（可以为 空），使得剩余元素的 和 能被 p 整除。 不允许 将整个数组都移除。
 *
 * 请你返回你需要移除的最短子数组的长度，如果无法满足题目要求，返回 -1 。
 *
 * 子数组 定义为原数组中连续的一组元素。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [3,1,4,2], p = 6
 * 输出：1
 * 解释：nums 中元素和为 10，不能被 p 整除。我们可以移除子数组 [4] ，剩余元素的和为 6 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [6,3,5,2], p = 9
 * 输出：2
 * 解释：我们无法移除任何一个元素使得和被 9 整除，最优方案是移除子数组 [5,2] ，剩余元素为 [6,3]，和为 9 。
 *
 *
 * 示例 3：
 *
 * 输入：nums = [1,2,3], p = 3
 * 输出：0
 * 解释：和恰好为 6 ，已经能被 3 整除了。所以我们不需要移除任何元素。
 *
 *
 * 示例  4：
 *
 * 输入：nums = [1,2,3], p = 7
 * 输出：-1
 * 解释：没有任何方案使得移除子数组后剩余元素的和被 7 整除。
 *
 *
 * 示例 5：
 *
 * 输入：nums = [1000000000,1000000000,1000000000], p = 3
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * 1 <= nums[i] <= 10^9
 * 1 <= p <= 10^9
 *
 *
 */

// @lc code=start
// !这个写得好
// https://leetcode.cn/problems/make-sum-divisible-by-p/solution/tao-lu-qian-zhui-he-ha-xi-biao-pythonjav-rzl0/
class Solution
{
public:
    int minSubarray(vector<int> &nums, int p)
    {
        int n = nums.size(), ans = n, s[n + 1];
        s[0] = 0;
        for (int i = 0; i < n; ++i)
            s[i + 1] = (s[i] + nums[i]) % p;
        int x = s[n];
        if (x == 0)
            return 0; // 移除空子数组（这行可以不要）

        unordered_map<int, int> last;
        for (int i = 0; i <= n; ++i)
        {
            last[s[i]] = i;
            auto it = last.find((s[i] - x + p) % p);
            if (it != last.end())
                ans = min(ans, i - it->second);
        }
        return ans < n ? ans : -1;
    }
};
// !只能过84 / 142个案例
// class Solution
// {
// public:
//     int minSubarray(vector<int> &nums, int p)
//     {
//         long long int sum = 0, ans = 214748364;
//         long long int le = 0, ri = 0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             sum += nums[i];
//         }
//         if (sum % p == 0)
//         {
//             return 0;
//         }
//         while (ri < nums.size())
//         {
//             while (sum % p != 0 && ri < nums.size())
//             {
//                 sum -= nums[ri];
//                 ri++;
//             }
//             cout << "1 ri le " << ri << " " << le << endl;
//             if (sum % p == 0 && sum > 0)
//             {
//                 ans = min(ri - le, ans);
//             }
//             sum += nums[le];
//             le++;
//             while (sum % p != 0 && le < ri)
//             {
//                 sum += nums[le];
//                 le++;
//             }
//             cout << "2 ri le " << ri << " " << le << endl;
//             if (sum % p == 0 && sum > 0)
//             {
//                 ans = min(ri - le, ans);
//             }
//         }
//         cout << sum;
//         if (ans == 214748364)
//         {
//             return -1;
//         }
//         return ans;
//     };
// };
// @lc code=end
