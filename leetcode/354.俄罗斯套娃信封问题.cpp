/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 *
 * https://leetcode.cn/problems/russian-doll-envelopes/description/
 *
 * algorithms
 * Hard (38.45%)
 * Likes:    876
 * Dislikes: 0
 * Total Accepted:    99.4K
 * Total Submissions: 259K
 * Testcase Example:  '[[5,4],[6,4],[6,7],[2,3]]'
 *
 * 给你一个二维整数数组 envelopes ，其中 envelopes[i] = [wi, hi] ，表示第 i 个信封的宽度和高度。
 *
 * 当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。
 *
 * 请计算 最多能有多少个 信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。
 *
 * 注意：不允许旋转信封。
 *
 *
 * 示例 1：
 *
 *
 * 输入：envelopes = [[5,4],[6,4],[6,7],[2,3]]
 * 输出：3
 * 解释：最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。
 *
 * 示例 2：
 *
 *
 * 输入：envelopes = [[1,1],[1,1],[1,1]]
 * 输出：1
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= envelopes.length <= 10^5
 * envelopes[i].length == 2
 * 1 <= wi, hi <= 10^5
 *
 *
 */

// @lc code=start
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
#define debug(a) cout << #a << "=" << a << endl;
#define lyh(i, a, b) for (int i = a; i <= b; i++)
#define hyl(i, a, b) for (int i = a; i >= b; i--)
#define LL long long

class Solution
{
public:
    /* 先对一边排序,这样就变成了最长严格递增子序列问题
    https://leetcode-cn.com/problems/russian-doll-envelopes/solution/e-luo-si-tao-wa-xin-feng-wen-ti-by-leetc-wj68/
     */
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        if (envelopes.empty())
        {
            return 0;
        }

        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [](const auto &e1, const auto &e2)
             { return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]); });

        vector<int> f(1, envelopes[0][1]);
        for (int i = 1; i < n; ++i)
        {
            if (int num = envelopes[i][1]; num > f.back())
            {
                f.emplace_back(num);
            }
            else
            {
                *lower_bound(f.begin(), f.end(), num) = num;
            }
        }
        return f.size();
    }
};
// @lc code=end
