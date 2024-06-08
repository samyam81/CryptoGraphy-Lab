# LAB-1: CryptoGraphy

Welcome to Lab-1! This repository is dedicated to providing a hands-on learning experience for cryptography enthusiasts. Whether you're a beginner or an experienced practitioner, CryptoGraphy-Lab offers a wealth of resources, implementations, and tutorials to deepen your understanding of cryptographic concepts and techniques.

## Prerequisites

To run or contribute to the code in this repository, you should have:

- Basic knowledge of Go programming language.
- Understanding of basic data structures such as arrays and matrix.
- Familiarity with algorithms of Cryptograpgy.

## Contents

1. **AdditiveModulo.go**:
   - This Go code defines a function `computeAdditiveInverse` that calculates the additive inverse of a number within a given modulo. It first ensures the number is within the modulo range, then computes its additive inverse accordingly. The commented-out `main` function demonstrates its usage by computing the additive inverse of 121 within a modulo of 54, though it's currently inactive.

2. **Co-prime.go**:
   - The `euclideanGCD` function calculates the greatest common divisor (GCD) of two integers using the Euclidean algorithm, which repeatedly divides the larger number by the smaller number until the remainder is zero, returning the last non-zero remainder. The `areCoPrime` function utilizes `euclideanGCD` to determine whether two integers are coprime, meaning they share no common factors other than 1. It returns true if the GCD of the two numbers is 1, indicating coprimality, and false otherwise.

3. **ExtendedEuclidean.go**:
   - This Go code defines the Extended Euclidean Algorithm (`ExtendedEuclideanAlgorithm`) to find the greatest common divisor (GCD) of two integers along with Bézout's coefficients. Additionally, there's a minor typo in the function name; it should be `ExtendedEuclideanAlgorithm` instead of `ExtendedEuclideaNAlgorithm`. The algorithm computes the GCD of `a` and `b` along with integers `x` and `y` such that `ax + by = gcd(a, b)`. This version of the algorithm extends the basic Euclidean Algorithm to calculate Bézout's coefficients as well.

4. **MultiPlicativeInverse.go**:
   - This Go code implements the Extended Euclidean Algorithm (`ExtendedEuclideanAlgorithm`) to find the greatest common divisor (GCD) of two integers along with Bézout's coefficients, and a function `multiplicativeInverse` to compute the multiplicative inverse of an integer `a` modulo `n`. The `multiplicativeInverse` function utilizes `ExtendedEuclideanAlgorithm` to find the inverse of `a` modulo `n`. If the GCD of `a` and `n` is 1, indicating `a` and `n` are coprime, it returns the multiplicative inverse of `a` modulo `n`. Otherwise, it returns -1 to indicate that the inverse doesn't exist. The commented-out `main` function demonstrates the usage of `multiplicativeInverse` by finding the multiplicative inverse of 17 modulo 43, though it's currently inactive.

5. **PlayFair.go**:
   - This Go code defines a Playfair Cipher implementation. The `PlayfairCipher` struct holds a key and a matrix for encryption. It has methods to initialize a new cipher with a given key, generate the encryption matrix, find positions of letters within the matrix, and encrypt plaintext. The `NewPlayfairCipher` function creates a new cipher with the given key and generates the encryption matrix. The `generateMatrix` method populates the 5x5 matrix with letters from the key and remaining alphabets in a specific order. The `encryptPair` method encrypts a pair of letters according to the Playfair Cipher rules. The `encrypt` method takes a plaintext, removes non-alphabetic characters, pads it with 'X' if needed, and encrypts it using the `encryptPair` method. Additionally, there are helper functions like `removeNonAlpha` to remove non-alphabetic characters, `isAlpha` to check if a character is alphabetic, and `toUpper` to convert a rune to uppercase byte.

6. **RailFence.go**:
   - This Go code implements the Rail Fence Cipher for both encryption and decryption. The `railFenceEncrypt` function takes an original string and a key (the number of rails) and encrypts the string using the Rail Fence Cipher. The `railFenceDecrypt` function takes an encrypted string and a key and decrypts the string using the Rail Fence Cipher. In both functions, the rail pattern is created using a slice of slices (`rail`), and characters are filled in according to the rail pattern. For encryption, characters are placed in a zigzag pattern across the rails. For decryption, the zigzag pattern is recreated and characters are read off in the original order. The commented-out `main` function allows for input of a message and a key, then demonstrates the encryption and decryption process, though it's currently inactive.

7. **ShiftCipher.go**:
   - These functions implement the Caesar Cipher algorithm for encryption and decryption. The `encrypt` function shifts each letter in the plaintext by a given key value while maintaining case and leaving non-alphabetic characters unchanged. The `decrypt` function reverses the encryption by shifting the ciphertext in the opposite direction.

8. **VignereShift.go**:
   - The Go code contains functions for encrypting and decrypting text using the Vigenère Cipher. In the `vigenereEncrypt` function, each letter of the plaintext is encrypted using the Vigenère Cipher with a key that is repeated if it's shorter than the plaintext. This process preserves case and leaves non-alphabetic characters unchanged. The `vigenereDecrypt` function reverses the encryption, decrypting the ciphertext using the Vigenère Cipher with the provided key. Additionally, helper functions `isLetter` and `isLower` are included to check if a character is a letter and if it's lowercase, respectively. Although the code includes a commented-out `main` function allowing user input for message and key to demonstrate the encryption and decryption process, it's currently inactive.

To get started:

1. Clone the repository:
    ```bash
    git clone https://github.com/samyam81/CryptoGraphy-Lab.git
    ```
2. Run the code that you want to run.

## Author
This project was created by [Samyam](https://github.com/samyam81).
