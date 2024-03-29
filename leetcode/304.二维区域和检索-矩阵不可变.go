/*
* @lc app=leetcode.cn id=304 lang=golang
*
* [304] 二维区域和检索 - 矩阵不可变
*
* https://leetcode.cn/problems/range-sum-query-2d-immutable/description/
*
  - algorithms
  - Medium (60.99%)
  - Likes:    469
  - Dislikes: 0
  - Total Accepted:    117.1K
  - Total Submissions: 191.8K
  - Testcase Example:  '["NumMatrix","sumRegion","sumRegion","sumRegion"]\n' +
    '[[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]'

*
* 给定一个二维矩阵 matrix，以下类型的多个请求：
*
*
* 计算其子矩形范围内元素的总和，该子矩阵的 左上角 为 (row1, col1) ，右下角 为 (row2, col2) 。
*
*
* 实现 NumMatrix 类：
*
*
* NumMatrix(int[][] matrix) 给定整数矩阵 matrix 进行初始化
* int sumRegion(int row1, int col1, int row2, int col2) 返回 左上角 (row1, col1)
* 、右下角 (row2, col2) 所描述的子矩阵的元素 总和 。
*
*
*
*
* 示例 1：
*
*
*
*
* 输入:
* ["NumMatrix","sumRegion","sumRegion","sumRegion"]
*
* [[[[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]],[2,1,4,3],[1,1,2,2],[1,2,2,4]]
* 输出:
* [null, 8, 11, 12]
*
* 解释:
* NumMatrix numMatrix = new
* NumMatrix([[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]]);
* numMatrix.sumRegion(2, 1, 4, 3); // return 8 (红色矩形框的元素总和)
* numMatrix.sumRegion(1, 1, 2, 2); // return 11 (绿色矩形框的元素总和)
* numMatrix.sumRegion(1, 2, 2, 4); // return 12 (蓝色矩形框的元素总和)
*
*
*
*
* 提示：
*
*
* m == matrix.length
* n == matrix[i].length
* 1 <= m, n <= 200
* -10^5 <= matrix[i][j] <= 10^5
* 0 <= row1 <= row2 < m
* 0 <= col1 <= col2 < n
* 最多调用 10^4 次 sumRegion 方法
*
*
*/
package main

// @lc code=start
type NumMatrix struct {
	sums [][]int
}

// !这和1139不一样，不需要使用up left两个数组，只要一个就能算和 这样相当于一维前缀和
// !在每次计算的时候仍然需要一个n的复杂度
//
//	func Constructor(matrix [][]int) NumMatrix {
//		arr := NumMatrix{
//			a: matrix,
//		}
//		arr.m = len(matrix)
//		arr.n = len(matrix[0])
//		arr.up = make([][]int, arr.m)
//		arr.left = make([][]int, arr.m)
//		for i := 0; i < arr.m; i++ {
//			arr.up[i] = make([]int, arr.n)
//			arr.left[i] = make([]int, arr.n)
//		}
//		arr.up[0][0], arr.left[0][0] = arr.a[0][0], arr.a[0][0]
//		for i := 1; i < arr.m; i++ {
//			arr.left[i][0] = arr.a[i][0]
//			arr.up[i][0] = arr.up[i-1][0] + arr.a[i][0]
//		}
//		for i := 1; i < arr.n; i++ {
//			arr.left[0][i] = arr.left[0][i-1] + arr.a[0][i]
//			arr.up[0][i] = arr.a[0][i]
//		}
//		for i := 1; i < arr.m; i++ {
//			for j := 1; j < arr.n; j++ {
//				arr.left[i][j] = arr.left[i][j-1] + arr.a[i][j]
//				arr.up[i][j] = arr.up[i-1][j] + arr.a[i][j]
//			}
//		}
//		return arr
//	}
//
// !  二维前缀和写法 https://leetcode.cn/problems/range-sum-query-2d-immutable/solution/er-wei-qu-yu-he-jian-suo-ju-zhen-bu-ke-b-2z5n/
func Constructor(matrix [][]int) NumMatrix {
	m := len(matrix)
	if m == 0 {
		return NumMatrix{}
	}
	n := len(matrix[0])
	sums := make([][]int, m+1)
	sums[0] = make([]int, n+1)
	for i, row := range matrix {
		sums[i+1] = make([]int, n+1)
		for j, v := range row {
			sums[i+1][j+1] = sums[i+1][j] + sums[i][j+1] - sums[i][j] + v
		}
	}
	return NumMatrix{sums}
}

func (nm *NumMatrix) SumRegion(row1, col1, row2, col2 int) int {
	return nm.sums[row2+1][col2+1] - nm.sums[row1][col2+1] - nm.sums[row2+1][col1] + nm.sums[row1][col1]
}

// func main() {
// 	obj := Constructor([][]int{{3, 0, 1, 4, 2}, {5, 6, 3, 2, 1}, {1, 2, 0, 1, 5}, {4, 1, 0, 1, 7}, {1, 0, 3, 0, 5}})
// 	fmt.Println(obj)
// }

/**
 * Your NumMatrix object will be instantiated and called as such:
 * obj := Constructor(matrix);
 * param_1 := obj.SumRegion(row1,col1,row2,col2);
 */
// @lc code=end
