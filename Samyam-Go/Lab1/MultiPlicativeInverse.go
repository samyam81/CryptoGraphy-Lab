package main

// import (
// 	"fmt"
// )

func ExtendedEuclideanAlgorithm(a, b int) (gcd, x, y int) {
    if a == 0 {
        return b, 0, 1
    }

    gcd, x1, y1 := ExtendedEuclideanAlgorithm(b%a, a)
    x = y1 - (b/a)*x1
    y = x1

    return gcd, x, y
}

func multiplicativeInverse(a,n int) int { 
	gcd, x, _ := ExtendedEuclideanAlgorithm(a, n)

	if gcd==1 {
		x=x%n
		if x<0 {
			x=x+n
		}
		return x
	} else{
		return -1
	}
}

// func main() {
// 	a := 17
// 	n := 43
// 	fmt.Printf("Multiplicative Inverse of %d modulo %d is: %d\n", a, n, multiplicativeInverse(a, n))
// }