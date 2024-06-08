package main

// import "fmt"

func computeAdditiveInverse(number, modulo int) int {
	number = number % modulo
	if number < 0 {
		number = number + modulo
	}
	return modulo - number
}

// func main() {
// 	AddInverse := computeAdditiveInverse(121, 54)
// 	fmt.Println(AddInverse)
// }
