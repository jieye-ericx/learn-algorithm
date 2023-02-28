/*
 * @lc app=leetcode.cn id=322 lang=golang
 *
 * [322] 零钱兑换
 *
 * https://leetcode.cn/problems/coin-change/description/
 *
 * algorithms
 * Medium (46.28%)
 * Likes:    2308
 * Dislikes: 0
 * Total Accepted:    582.2K
 * Total Submissions: 1.3M
 * Testcase Example:  '[1,2,5]\n11'
 *
 * 给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
 *
 * 计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
 *
 * 你可以认为每种硬币的数量是无限的。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：coins = [1, 2, 5], amount = 11
 * 输出：3
 * 解释：11 = 5 + 5 + 1
 *
 * 示例 2：
 *
 *
 * 输入：coins = [2], amount = 3
 * 输出：-1
 *
 * 示例 3：
 *
 *
 * 输入：coins = [1], amount = 0
 * 输出：0
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= coins.length <= 12
 * 1 <= coins[i] <= 2^31 - 1
 * 0 <= amount <= 10^4
 *
 *
 */

// @lc code=start
// ! 看完答案后写的动态规划
func coinChange(coins []int, amount int) int {
	sort.Ints(coins)
	f := make([]int, amount+1)
	for i := 1; i < amount+1; i++ {
		f[i] = 0xffffff
	}
	f[0] = 0
	for i := 1; i <= amount; i++ {
		for j := 0; j < len(coins); j++ {
			if coins[j] > i {
				break
			}
			f[i] = min(f[i], f[i-coins[j]]+1)
		}
	}
	if f[amount] == 0xffffff {
		return -1
	}
	return f[amount]
}
func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

// ! 我写的超时递归
//
//	func coinChange(coins []int, amount int) int {
//		// ok := false
//		ans := 0xfffff
//		sort.Ints(coins)
//		var dfs func(int, int, int)
//		dfs = func(remain, nums, tmpI int) {
//			if nums > ans {
//				return
//			}
//			if remain == 0 {
//				// ok = true
//				ans = min(nums, ans)
//				return
//			}
//			for i := tmpI; i >= 0; i-- {
//				if coins[i] > remain {
//					continue
//				}
//				times := remain / coins[i]
//				// !我说怎么感觉这个方法有点熟悉 不就是多重背包吗 我这样写递归会超时
//				for j := times; j >= 0; j-- {
//					dfs(remain-coins[i]*j, nums+j, i-1)
//				}
//			}
//		}
//		dfs(amount, 0, len(coins)-1)
//		if ans == 0xfffff {
//			return -1
//		} else {
//			return ans
//		}
//	}
func min(x, y int) int {
	if x < y {
		return x
	}
	return y
}

// @lc code=end
