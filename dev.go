package main

import "fmt"

func main() {
	c := make(chan int)
	for i := 0; i <= 10; i++ {
		fmt.Println(111)
		c <- i
	}
	go func() {
		for item := range c {
			fmt.Println(item)
		}
	}()
}
