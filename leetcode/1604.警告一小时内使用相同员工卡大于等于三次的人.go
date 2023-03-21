/*
 * @lc app=leetcode.cn id=1604 lang=golang
 *
 * [1604] 警告一小时内使用相同员工卡大于等于三次的人
 *
 * https://leetcode.cn/problems/alert-using-same-key-card-three-or-more-times-in-a-one-hour-period/description/
 *
 * algorithms
 * Medium (42.51%)
 * Likes:    74
 * Dislikes: 0
 * Total Accepted:    18.2K
 * Total Submissions: 36.8K
 * Testcase Example:  '["daniel","daniel","daniel","luis","luis","luis","luis"]\n' +
 * '["10:00","10:40","11:00","09:00","11:00","13:00","15:00"]'
 *
 *
 * 力扣公司的员工都使用员工卡来开办公室的门。每当一个员工使用一次他的员工卡，安保系统会记录下员工的名字和使用时间。如果一个员工在一小时时间内使用员工卡的次数大于等于三次，这个系统会自动发布一个
 * 警告 。
 *
 * 给你字符串数组 keyName 和 keyTime ，其中 [keyName[i], keyTime[i]] 对应一个人的名字和他在 某一天
 * 内使用员工卡的时间。
 *
 * 使用时间的格式是 24小时制 ，形如 "HH:MM" ，比方说 "23:51" 和 "09:49" 。
 *
 * 请你返回去重后的收到系统警告的员工名字，将它们按 字典序升序 排序后返回。
 *
 * 请注意 "10:00" - "11:00" 视为一个小时时间范围内，而 "23:51" - "00:10"
 * 不被视为一小时内，因为系统记录的是某一天内的使用情况。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：keyName = ["daniel","daniel","daniel","luis","luis","luis","luis"],
 * keyTime = ["10:00","10:40","11:00","09:00","11:00","13:00","15:00"]
 * 输出：["daniel"]
 * 解释："daniel" 在一小时内使用了 3 次员工卡（"10:00"，"10:40"，"11:00"）。
 *
 *
 * 示例 2：
 *
 *
 * 输入：keyName = ["alice","alice","alice","bob","bob","bob","bob"], keyTime =
 * ["12:01","12:00","18:00","21:00","21:20","21:30","23:00"]
 * 输出：["bob"]
 * 解释："bob" 在一小时内使用了 3 次员工卡（"21:00"，"21:20"，"21:30"）。
 *
 *
 * 示例 3：
 *
 *
 * 输入：keyName = ["john","john","john"], keyTime = ["23:58","23:59","00:01"]
 * 输出：[]
 *
 *
 * 示例 4：
 *
 *
 * 输入：keyName = ["leslie","leslie","leslie","clare","clare","clare","clare"],
 * keyTime = ["13:00","13:20","14:00","18:00","18:51","19:30","19:49"]
 * 输出：["clare","leslie"]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1
 * keyName.length == keyTime.length
 * keyTime 格式为 "HH:MM" 。
 * 保证 [keyName[i], keyTime[i]] 形成的二元对 互不相同 。
 * 1
 * keyName[i] 只包含小写英文字母。
 *
 *
 */

// @lc code=start
package main

import (
	"sort"
	"strconv"
	"strings"
)

func alertNames(keyName []string, keyTime []string) []string {
	// m := make(map[string]int)
	mm := make(map[string][]string)
	ans := make(map[string]int)
	for i, v := range keyName {
		mm[v] = append(mm[v], keyTime[i])
	}
	for k, v := range mm {
		sort.Strings(v)
		for i := 0; i < len(v)-2; i++ {
			if getTime(v[i+2])-getTime(v[i]) <= 60 {
				ans[k] = 1
			}
		}
	}

	// for k := range m {
	// 	fmt.Println(k, m[k])
	// }
	aa := getKeys2(ans)
	sort.Strings(aa)
	return aa
}
func getTime(s string) int {
	hm := strings.Split(s, ":")
	q, _ := strconv.Atoi(hm[0])
	w, _ := strconv.Atoi(hm[1])
	return q*60 + w
}
func getKeys2(m map[string]int) []string {
	// 数组默认长度为map长度,后面append时,不需要重新申请内存和拷贝,效率很高
	keys := make([]string, 0, len(m))
	for k := range m {
		keys = append(keys, k)
	}
	return keys
}

// func main() {
// fmt.Println(alertNames([]string{"leslie", "leslie", "leslie", "clare", "clare", "clare", "clare"}, []string{"13:00", "13:20", "14:00", "18:00", "18:51", "19:30", "19:49"}))
// fmt.Println(alertNames([]string{"a", "a", "a", "a", "a", "a", "b", "b", "b", "b", "b"}, []string{"23:27", "03:14", "12:57", "13:35", "13:18", "21:58", "22:39", "10:49", "19:37", "14:14", "10:41"}))
// ["john","john","john"]
// ["23:58","23:59","00:01"]
// 	fmt.Println(alertNames([]string{"john", "john", "john"}, []string{"23:58", "23:59", "00:01"}))
// }

// @lc code=end

// 我的方法适合于keyName中一会是a一会是b的情况，但是需要保证时间顺序是递增的，因为实际情况时间可能是乱的，所以就不适用了
// for i, v := range keyName {
// 		_, o := ans[v]
// 		if o {
// 			continue
// 		}
// 		t = getTime(keyTime[i])
// 		lt11, _ := lt1[v]
// 		lt12, _ := lt2[v]
// 		fmt.Println(v, m[v], t, lt11, lt12)
// 		if m[v] == 0 {
// 			lt1[v] = t
// 			m[v] = 1
// 		} else if m[v] == 1 {
// 			if t-lt11 <= 60 && t-lt11 > 0 {
// 				m[v] = 2
// 				lt2[v] = t
// 			} else {
// 				lt1[v] = t
// 			}
// 		} else if m[v] == 2 {
// 			if t-lt11 <= 60 && t-lt11 > 0 {
// 				m[v] = 3
// 				ans[v] = 1
// 			} else {
// 				if t-lt12 <= 60 && t-lt12 > 0 {
// 					m[v] = 2
// 					lt1[v] = lt2[v]
// 					lt2[v] = t
// 				} else {
// 					m[v] = 1
// 					lt1[v] = t
// 				}
// 			}
// 		}
// 	}
