package main

// import (
// 	"fmt"
// )

func vigenereEncrypt(plaintext, key string) string {
	ciphertext := ""
	for i := 0; i < len(plaintext); i++ {
		c := plaintext[i]
		k := key[i%len(key)] // Repeats key if shorter than plaintext
		if !isLetter(c) {
			ciphertext += string(c) // Non-letter characters remain unchanged
		} else {
			base := byte('A')
			if isLower(c) {
				base = 'a'
			}
			ciphertext += string((int(c-base)+int(k-'A'))%26 + int(base))
		}
	}
	return ciphertext
}

func vigenereDecrypt(ciphertext, key string) string {
	plaintext := ""
	for i := 0; i < len(ciphertext); i++ {
		c := ciphertext[i]
		k := key[i%len(key)] // Repeats key if shorter than ciphertext
		if !isLetter(c) {
			plaintext += string(c) // Non-letter characters remain unchanged
		} else {
			base := byte('A')
			if isLower(c) {
				base = 'a'
			}
			plaintext += string((int(c-base+26)-int(k-'A'))%26 + int(base))
		}
	}
	return plaintext
}

func isLetter(c byte) bool {
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
}

func isLower(c byte) bool {
	return c >= 'a' && c <= 'z'
}

// func main() {
// 	var message, key string

// 	// Input message and key
// 	fmt.Println("Enter the message: ")
// 	fmt.Scanln(&message)
// 	fmt.Println("Enter the key: ")
// 	fmt.Scanln(&key)

// 	// Encryption
// 	encrypted := vigenereEncrypt(message, key)
// 	fmt.Println("Encrypted message: ", encrypted)

// 	// Decryption
// 	decrypted := vigenereDecrypt(encrypted, key)
// 	fmt.Println("Decrypted message: ", decrypted)
// }
