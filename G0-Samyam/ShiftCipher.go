package main

import (
    "fmt"
)

func main() {
    var PlainText string
    var key int

    fmt.Println("Enter your Plain-text")
    fmt.Scanf("%s", &PlainText)

   	fmt.Println("Enter your key! (0-25) ")
	_, err := fmt.Scan(&key)
		if err != nil {
    		fmt.Println("Error:", err)
    		return
		}	

    encrypted := encrypt(PlainText, key)
    fmt.Println("The encrypted message is", encrypted)

    decrypted := decrypt(encrypted, key)
    fmt.Println("The decrypted message is", decrypted)
}

func encrypt(plaintext string, key int) string {
    ciphertext := ""

    for _, c := range plaintext {
        if c >= 'A' && c <= 'Z' {
            base := 'A'
            ciphertext += string((c-base+int32(key))%26 + base)
        } else if c >= 'a' && c <= 'z' {
            base := 'a'
            ciphertext += string((c-base+int32(key))%26 + base)
        } else {
            ciphertext += string(c)
        }
    }

    return ciphertext
}

func decrypt(ciphertext string, key int) string {
    return encrypt(ciphertext, 26-key)
}
