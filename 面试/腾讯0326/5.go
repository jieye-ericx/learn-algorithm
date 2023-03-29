// 牛妹在生日这一天收到了一个长度为n的序列a1，a2，…,an。
// 牛妹希望从这个序列中删除一些数，使得剩下的元素的最大公约数恰好等于k。
// 牛妹想知道有多少种删除的方案。由于答案可能过大，请对10^9+7取模。
// 最大公约数:指两个或多个整数公有约数中最大的一个。
// 输入
// 4 2
// 2 3 4 8
// 输出
// 4
package main

import (
	"fmt"
)

func gcd(a, b int) int {
	if b == 0 {
		return a
	}
	return gcd(b, a%b)
}

var a []int
var n, k int

const M = 1e9 + 7

func main() {
	fmt.Scanf("%d%d", &n, &k)
	a = make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&a[i])
	}
	fmt.Println(comp())
}

func comp() int {
	dp := make([][]int, n+1)
	for i := range dp {
		dp[i] = make([]int, k+1)
	}
	dp[0][0] = 1
	for i := 1; i < n; i++ {
		for j := 0; j <= k; j++ {
			dp[i][j] = dp[i-1][j]
			gg := gcd(j, a[i-1])
			if gg == k {
				dp[i][k] = (dp[i][k] + dp[i-1][j]) % M
			} else if gg != j {
				dp[i][gg] = (dp[i][gg] + dp[i-1][j]) % M
				dp[i][j] = (dp[i][j] + dp[i-1][j]) % M
			}
		}
	}
	return dp[n][k]
}
