/*
 * @lc app=leetcode.cn id=813 lang=golang
 *
 * [813] 最大平均值和的分组
 *
 * https://leetcode.cn/problems/largest-sum-of-averages/description/
 *
 * algorithms
 * Medium (56.28%)
 * Likes:    244
 * Dislikes: 0
 * Total Accepted:    11K
 * Total Submissions: 19.4K
 * Testcase Example:  '[9,1,2,3,9]\n3'
 *
 * 给定数组 nums 和一个整数 k 。我们将给定的数组 nums 分成 最多 k 个相邻的非空子数组 。 分数 由每个子数组内的平均值的总和构成。
 *
 * 注意我们必须使用 nums 数组中的每一个数进行分组，并且分数不一定需要是整数。
 *
 * 返回我们所能得到的最大 分数 是多少。答案误差在 10^-6 内被视为是正确的。
 *
 *
 *
 * 示例 1:
 *
 *
 * 输入: nums = [9,1,2,3,9], k = 3
 * 输出: 20.00000
 * 解释:
 * nums 的最优分组是[9], [1, 2, 3], [9]. 得到的分数是 9 + (1 + 2 + 3) / 3 + 9 = 20.
 * 我们也可以把 nums 分成[9, 1], [2], [3, 9].
 * 这样的分组得到的分数为 5 + 2 + 6 = 13, 但不是最大值.
 *
 *
 * 示例 2:
 *
 *
 * 输入: nums = [1,2,3,4,5,6,7], k = 4
 * 输出: 20.50000
 *
 *
 *
 *
 * 提示:
 *
 *
 * 1 <= nums.length <= 100
 * 1 <= nums[i] <= 10^4
 * 1 <= k <= nums.length
 *
 *
 */
package main

import (
	"math"
)

// @lc code=start
func largestSumOfAverages(nums []int, k int) float64 {
	n := len(nums)
	prefix := make([]float64, n+1)
	for i, x := range nums {
		prefix[i+1] = prefix[i] + float64(x)
	}
	dp := make([][]float64, n+1)
	for i := range dp {
		dp[i] = make([]float64, k+1)
	}
	for i := 1; i <= n; i++ {
		dp[i][1] = prefix[i] / float64(i)
	}
	for j := 2; j <= k; j++ {
		for i := j; i <= n; i++ {
			for x := j - 1; x < i; x++ {
				dp[i][j] = math.Max(dp[i][j], dp[x][j-1]+(prefix[i]-prefix[x])/float64(i-x))
			}
		}
	}
	return dp[n][k]
}

// !我的方法超时了
// func largestSumOfAverages(nums []int, k int) float64 {
// 	n := len(nums)
// 	return doit(math.MinInt64, 0, k, 0, n, 0, 0, -1, nums)
// }
// func doit(maxans, ans float64, k, tmpk, n, tmpn, c, precn int, nums []int) float64 {
// 	if tmpk == k && tmpn != n {
// 		return 0
// 	}
// 	if tmpn == n {
// 		fmt.Println(111)
// 		fmt.Println(maxans, ans, k, tmpk, n, tmpn, c, precn)
// 		if precn != n-1 {

// 			v := tmpn - 1 - precn
// 			ans = ans + float64(c)/float64(v)
// 		}
// 		fmt.Println(maxans, ans, k, tmpk, n, tmpn, c, precn)
// 		if ans > maxans {
// 			maxans = ans
// 		}
// 		return maxans
// 	}
// 	// 到tmpn结束
// 	cc := c + nums[tmpn]
// 	v := tmpn - precn
// 	maxans1 := doit(maxans, ans+float64(cc)/float64(v), k, tmpk+1, n, tmpn+1, 0, tmpn, nums)
// 	// 到tmpn不结束
// 	maxans2 := doit(maxans, ans, k, tmpk, n, tmpn+1, c+nums[tmpn], precn, nums)
// 	if maxans1 > maxans2 {
// 		return maxans1
// 	} else {
// 		return maxans2
// 	}
// }
// func main() {
// 	//函数体
// 	fmt.Println("21312")
// 	fmt.Println(largestSumOfAverages([]int{9, 1, 2, 3, 9}, 3))
// }

//超时了。。。

// @lc code=end
