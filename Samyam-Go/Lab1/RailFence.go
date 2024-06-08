package main

// import (
// 	"fmt"
// )

func railFenceEncrypt(original string, key int) string {
	encrypted := ""
	rail := make([][]byte, key)
	for i := range rail {
		rail[i] = make([]byte, len(original))
	}

	row, direction := 0, 1

	for i, char := range original {
		rail[row][i] = byte(char)
		row += direction
		if row == key-1 || row == 0 {
			direction = -direction // Change direction at the edges
		}
	}

	for _, row := range rail {
		for _, ch := range row {
			if ch != 0 {
				encrypted += string(ch)
			}
		}
	}

	return encrypted
}

func railFenceDecrypt(encrypted string, key int) string {
	decrypted := ""
	rail := make([][]byte, key)
	for i := range rail {
		rail[i] = make([]byte, len(encrypted))
	}

	i, j, direction := 0, 0, 1

	for _, char := range encrypted {
		char='*'
		rail[j][i] = byte(char)
		if j == key-1 {
			direction = -1 // Change direction when reaching bottom rail
		} else if j == 0 {
			direction = 1 // Change direction when reaching top rail
		}
		j += direction
		i++
	}

	index := 0
	for i := range rail {
		for j := range rail[i] {
			if rail[i][j] == '*' {
				rail[i][j] = encrypted[index]
				index++
			}
		}
	}

	i, j, direction = 0, 0, 1
	for range encrypted { // Removed char variable, since it's not used
		decrypted += string(rail[j][i])
		if j == key-1 {
			direction = -1 // Change direction when reaching bottom rail
		} else if j == 0 {
			direction = 1 // Change direction when reaching top rail
		}
		j += direction
		i++
	}

	return decrypted
}

// func main() {
// 	var message string
// 	var key int

// 	// Input message and key
// 	fmt.Println("Enter the message: ")
// 	fmt.Scanln(&message)
// 	fmt.Println("Enter the key: ")
// 	fmt.Scanln(&key)

// 	// Encryption
// 	encrypted := railFenceEncrypt(message, key)
// 	fmt.Println("Encrypted message: ", encrypted)

// 	// Decryption
// 	decrypted := railFenceDecrypt(encrypted, key)
// 	fmt.Println("Decrypted message: ", decrypted)
// }
