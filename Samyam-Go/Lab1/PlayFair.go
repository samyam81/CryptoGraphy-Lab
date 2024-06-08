package main

import (
    "strings"
)

type PlayfairCipher struct {
    key    string
    matrix [5][5]byte
}

func NewPlayfairCipher(key string) *PlayfairCipher {
    cipher := &PlayfairCipher{key: key}
    cipher.generateMatrix()
    return cipher
}

func (p *PlayfairCipher) generateMatrix() {
    k := 0
    used := [26]bool{}

    for _, c := range p.key {
        if !isAlpha(byte(c)) {
            continue
        }
        uc := toUpper(c)
        if !used[uc-'A'] && uc != 'J' {
            p.matrix[k/5][k%5] = byte(uc)
            used[uc-'A'] = true
            k++
        }
    }

    for c := byte('A'); c <= 'Z'; c++ {
        if c == 'J' {
            continue
        }
        if !used[c-'A'] {
            p.matrix[k/5][k%5] = c
            k++
        }
    }
}

func (p *PlayfairCipher) findPosition(letter byte) (int, int) {
    for i := 0; i < 5; i++ {
        for j := 0; j < 5; j++ {
            if p.matrix[i][j] == letter {
                return i, j
            }
        }
    }
    return -1, -1
}

func (p *PlayfairCipher) encryptPair(a, b byte) string {
    if a == b {
        b = 'X'
    }

    posA1, posA2 := p.findPosition(a)
    posB1, posB2 := p.findPosition(b)

    if posA1 == posB1 {
        return string(p.matrix[posA1][(posA2+1)%5]) +
            string(p.matrix[posB1][(posB2+1)%5])
    } else if posA2 == posB2 {
        return string(p.matrix[(posA1+1)%5][posA2]) +
            string(p.matrix[(posB1+1)%5][posB2])
    } else {
        return string(p.matrix[posA1][posB2]) +
            string(p.matrix[posB1][posA2])
    }
}


func (p *PlayfairCipher) encrypt(plaintext string) string {
    encryptedText := ""

    plaintext = removeNonAlpha(plaintext)

    if len(plaintext)%2 != 0 {
        plaintext += "X"
    }

    for i := 0; i < len(plaintext); i += 2 {
        a := toUpper(rune(plaintext[i]))
        b := toUpper(rune(plaintext[i+1]))
        encryptedText += p.encryptPair(byte(a), byte(b))
    }

    return encryptedText
}

func removeNonAlpha(s string) string {
    return strings.Map(func(r rune) rune {
        if isAlpha(byte(r)) {
            return r
        }
        return -1
    }, s)
}

func isAlpha(c byte) bool {
    return 'A' <= c && c <= 'Z'
}

func toUpper(c rune) byte {
    return byte(strings.ToUpper(string(c))[0])
}

