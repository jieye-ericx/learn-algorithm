package main

import "fmt"

func main() {
	t := "zdz"
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
	for _, v := range t {
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

		ans += "!"
		nowi = si[int(v)]
		nowj = sj[int(v)]
	}
	fmt.Println(ans)
	// fmt.Println(int(t[2]), si[int(t[2])], sj[int(t[2])])
	// fmt.Println(int(t[1]), si[int(t[1])], sj[int(t[1])])
}
