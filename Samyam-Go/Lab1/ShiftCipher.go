package main

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