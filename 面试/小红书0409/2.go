/*
实验室需要配制一种溶液。现在，研究员面前有n种该物质的溶液，每一种有无限多瓶，第i种的溶液体积为xi，里面含有yi单位的该物质。研究员每次可以选择一瓶溶液，将其倒入另外一瓶（假设瓶子的容量无限），即可以看作将两个瓶子内的溶液合并。此时合并的溶液体积和物质含量都等于之前两个瓶子内的之和。
特别地，如果瓶子A与B的溶液体积相同，那么A与B合并之后该物质的含量会产生化学反应，使得该物质含量增加x单位。
研究员的任务是配制溶液体积恰好等于C的，且尽量浓的溶液(即物质含量尽量多）。研究员想要知道物质含量最多是多少。

输入描述
第一行三个正整数n,X,C;
第二行n个正整数x1,x2,...,Xn，中间用空格隔开；
第三行八个正整数y1,y2,...,yn，中间用空格隔开。
对于所有数据，1<=n,x,C,Yi≤1000,1≤xi≤C

输出描述
输出一行一个整数，表示答案。

样例输入
3 4 16
5 3 4
2 4 1
输出
29
*/
package main

import "fmt"

var n, X, C int

func main() {
	fmt.Scan(&n, &X, &C)
	x := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&x[i])
	}
	y := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&y[i])
	}

	dp := make([][]int, C+1)
	for i := 0; i <= C; i++ {
		dp[i] = make([]int, X+1)
	}
	for i := 1; i <= C; i++ {
		for j := 0; j <= X; j++ {
			dp[i][j] = -1
		}
	}
	dp[0][0] = 0
	for i := 1; i <= n; i++ {
		for v := C; v >= x[i-1]; v-- {
			for j := X; j >= 0; j-- {
				if dp[v-x[i-1]][j] != -1 {
					dp[v][j] = max(dp[v][j], dp[v-x[i-1]][j]+y[i-1])
				}
				if j > 0 && dp[v-x[i-1]][j-1] != -1 {
					dp[v][j] = max(dp[v][j], dp[v-x[i-1]][j-1]+x[i-1])

				}
			}
		}
	}
	ans := -1
	for j := X; j >= 0; j-- {
		ans = max(ans, dp[C][j])
	}
	fmt.Println(ans)
}

func comp() {

}
func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
