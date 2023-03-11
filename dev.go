package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	in := bufio.NewScanner(os.Stdin)
	in.Scan()
	for in.Scan() {
		str := in.Text()

		fmt.Println(str) //将切片连接成字符串
	}
}
