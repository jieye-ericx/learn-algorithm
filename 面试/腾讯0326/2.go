/*
给定N个字符串，每个字符串全部由小写字母组成，且每个字符串的长度最多为8，请你判断有多少重组字符串，重组字符串有以下规则：
1.从每个字符串里面都抽取1个字母组成
2.新字符串不能有2个相同的字母
请问总共能组成多少个重组字符串
输入描述：
第一行输入整数为N
第二行到第N＋1行输入N个字符串，全部由小写字母组成
2<=N<=6
1<=len（字符串)<=8
输出描述：
输出一个整数，代表总共能组成多少个重组字符串
示例：
输入：
3
ab
ca
ccb
输出：
2
给出go代码
*/
package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	strs := make([]string, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&strs[i])
	}
	fmt.Println(len(comp(strs)))
}

func comp(strs []string) []string {

	var res []string
	var path []byte

	resm := map[string]int{}
	used := map[byte]int{}
	// for i := range used {
	// 	used[i] = map[string]int{}
	// }
	var backf func(index int)
	backf = func(index int) {
		if index == len(strs) {
			newans := string(path)
			if resm[newans] == 0 {
				res = append(res, string(path))
				resm[newans] = 1
			}
			return
		}
		ss := strs[index]
		for i := 0; i < len(ss); i++ {
			ch := ss[i]
			if used[ch] == 0 {
				path = append(path, ch)
				used[ch] = 1
				backf(index + 1)
				used[ch] = 0
				path = path[:len(path)-1]
			}
		}
	}
	backf(0)
	fmt.Print(res)
	return res
}
