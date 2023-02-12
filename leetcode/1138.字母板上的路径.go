/*
 * @lc app=leetcode.cn id=1138 lang=golang
 *
 * [1138] 字母板上的路径
 *
 * https://leetcode.cn/problems/alphabet-board-path/description/
 *
 * algorithms
 * Medium (44.42%)
 * Likes:    106
 * Dislikes: 0
 * Total Accepted:    22.6K
 * Total Submissions: 44.2K
 * Testcase Example:  '"leet"'
 *
 * 我们从一块字母板上的位置 (0, 0) 出发，该坐标对应的字符为 board[0][0]。
 *
 * 在本题里，字母板为board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"]，如下所示。
 *
 *
 *
 * 我们可以按下面的指令规则行动：
 *
 *
 * 如果方格存在，'U' 意味着将我们的位置上移一行；
 * 如果方格存在，'D' 意味着将我们的位置下移一行；
 * 如果方格存在，'L' 意味着将我们的位置左移一列；
 * 如果方格存在，'R' 意味着将我们的位置右移一列；
 * '!' 会把在我们当前位置 (r, c) 的字符 board[r][c] 添加到答案中。
 *
 *
 * （注意，字母板上只存在有字母的位置。）
 *
 * 返回指令序列，用最小的行动次数让答案和目标 target 相同。你可以返回任何达成目标的路径。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：target = "leet"
 * 输出："DDR!UURRR!!DDD!"
 *
 *
 * 示例 2：
 *
 *
 * 输入：target = "code"
 * 输出："RR!DDRR!UUL!R!"
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= target.length <= 100
 * target 仅含有小写英文字母。
 *
 *
 */

// @lc code=start
func alphabetBoardPath(target string) string {
	si := make(map[int]int)
	sj := make(map[int]int)
	i := 97
	for k := 0; k <= 5; k++ {
		for l := 0; l <= 4; l++ {
			si[i] = k
			sj[i] = l

			if i == 122 {
				break
			}
			i++
		}
	}
	nowi, nowj := 0, 0
	ans := ""
	nowz := false
	for _, v := range target {
		if v == 'z' {

			if nowz {
				ans += "!"
				continue
			} else {
				nowz = true

				v = 'u'
			}
		} else {
			if nowz {
				ans += "U"
				nowz = false
			}
		}
		if si[int(v)]-nowi > 0 {
			for i := 0; i < si[int(v)]-nowi; i++ {
				ans += "D"
			}
		} else {
			for i := 0; i < nowi-si[int(v)]; i++ {
				ans += "U"
			}
		}
		if sj[int(v)]-nowj > 0 {
			for i := 0; i < sj[int(v)]-nowj; i++ {
				ans += "R"
			}
		} else {
			for i := 0; i < nowj-sj[int(v)]; i++ {
				ans += "L"
			}
		}
		if nowz {
			ans += "D"
			// ! 注意以上一下，下要在最后一步，因为防止走到52，53这些位置
		}
		ans += "!"
		nowi = si[int(v)]
		nowj = sj[int(v)]
	}
	return ans
}

// @lc code=end
