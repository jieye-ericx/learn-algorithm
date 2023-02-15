package main

import (
	"fmt"
	"sort"
)

func main() {
	str := "WWEQERQWQWWRWWERQWEQ"
	cnt := make([]int, 4)
	base, ans := len(str)/4, 0
	for _, v := range str {
		switch v {
		case 'Q':
			cnt[0] += 1
		case 'W':
			cnt[1] += 1
		case 'E':
			cnt[2] += 1
		case 'R':
			cnt[3] += 1
		}
	}
	sort.Ints(cnt)
	for _, v := range cnt {
		cha := base - v
		if cha > 0 {
			for i := 3; i >= 0; i-- {
				if cnt[i]-cha >= base {
					cnt[i] -= cha
					ans += cha
					break
				} else {
					cha -= cnt[i] - base
					ans += cnt[i] - base
					cnt[i] = base
				}
			}
		}
	}
	fmt.Println(ans)
}
