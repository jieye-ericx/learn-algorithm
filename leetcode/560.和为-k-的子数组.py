#
# @lc app=leetcode.cn id=560 lang=python3
#
# [560] 和为 K 的子数组
#
# https://leetcode-cn.com/problems/subarray-sum-equals-k/description/
#
# algorithms
# Medium (44.59%)
# Likes:    1359
# Dislikes: 0
# Total Accepted:    193.4K
# Total Submissions: 431.4K
# Testcase Example:  '[1,1,1]\n2'
#
# 给你一个整数数组 nums 和一个整数 k ，请你统计并返回该数组中和为 k 的连续子数组的个数。
#
#
#
# 示例 1：
#
#
# 输入：nums = [1,1,1], k = 2
# 输出：2
#
#
# 示例 2：
#
#
# 输入：nums = [1,2,3], k = 3
# 输出：2
#
#
#
#
# 提示：
#
#
# 1 <= nums.length <= 2 * 10^4
# -1000 <= nums[i] <= 1000
# -10^7 <= k <= 10^7
#
#
#

# @lc code=start
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        d = {0: 1}
        pre = ans = 0
        for x in nums:
            pre += x
            if pre-k in d:
                ans += d[pre-k]
            if pre in d:
                d[pre] += 1
            else:
                d[pre] = 1
        return ans

    # def subarraySum(self, nums: List[int], k: int) -> int:
    #     n = len(nums)
    #     if n == 1:
    #         if nums[0] == k:
    #             return 1
    #         else:
    #             return 0
    #     i = ans = j = 0
    #     flag = 0
    #     tmp = nums[i]
    #     while i < n and j < n and i <= j:
    #         if tmp<k:
    #             while tmp < k and j < n:
    #                 j += 1
    #                 tmp += nums[j]
    #         elif tmp>k:

    #         if tmp == k:
    #             ans += 1
    #             tmp -= nums[i]
    #             i += 1
    #         if j == n-1:
    #             break

        return ans
        # @lc code=end
