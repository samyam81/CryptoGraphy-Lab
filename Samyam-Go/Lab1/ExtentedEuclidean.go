package main


func ExtendedEuclideaNAlgorithm(a, b int) (gcd, x, y int) {
    if a == 0 {
        return b, 0, 1
    }

    gcd, x1, y1 := ExtendedEuclideanAlgorithm(b%a, a)
    x = y1 - (b/a)*x1
    y = x1

    return gcd, x, y
}

// func main() {
//     a, b := 56, 15
//     gcd, x, y := ExtendedEuclideanAlgorithm(a, b)
//     fmt.Printf("gcd(%d, %d) = %d\n", a, b, gcd)
//     fmt.Printf("%d * %d + %d * %d = %d\n", a, x, b, y, gcd)
// }

