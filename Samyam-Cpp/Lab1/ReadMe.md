# LAB-1: CryptoGraphy

Welcome to Lab-1! This repository is dedicated to providing a hands-on learning experience for cryptography enthusiasts. Whether you're a beginner or an experienced practitioner, CryptoGraphy-Lab offers a wealth of resources, implementations, and tutorials to deepen your understanding of cryptographic concepts and techniques.

## Prerequisites

To run or contribute to the code in this repository, you should have:

- Basic knowledge of C++ programming language.
- Understanding of basic data structures such as arrays and matrix.
- Familiarity with algorithms of Cryptograpgy.

## Contents

1. **AdditiveModulo.cpp**:
   - This C++ program computes the additive inverse of a given number modulo another number. It defines a function `computeAdditiveInverse` that takes two integers, `number` and `modulo`, and returns the additive inverse of `number` modulo `modulo`. The function handles negative numbers by applying the modulo operation to ensure the result is within the range [0, modulo - 1]. In the `main` function, it prompts the user to enter the number and the modulo, computes the additive inverse using the defined function, and then prints the result.

2. **CoPrime.cpp**:
   - This C++ program determines whether two given numbers are coprime or not. It first defines a function `euclideanGCD` to calculate the greatest common divisor (GCD) of two numbers using the Euclidean algorithm. Then, it defines a function `areCoprime` that checks if the GCD of two numbers is 1, indicating that they are coprime. In the `main` function, it prompts the user to enter two numbers, calculates their GCD using `areCoprime`, and prints whether they are coprime or not based on the result.

3. **EuclideanAlgorithm.cpp**:
   - This C++ program calculates the greatest common divisor (GCD) of two given numbers using the Euclidean algorithm. It defines a function `euclideanGCD` to iteratively compute the GCD of two integers `a` and `b` until `b` becomes zero, updating `a` and `b` accordingly. In the `main` function, it prompts the user to enter two numbers, calculates their GCD using the defined function, and then prints the result.

4. **ExtendedEuclidean.cpp**:
   - This C++ program implements the Extended Euclidean Algorithm to find the coefficients \( x \) and \( y \) such that \( ax + by = \text{gcd}(a, b) \) for given integers \( a \) and \( b \). The function `extendedEuclideanAlgorithm` takes two integers \( a \) and \( b \) and returns a vector of vectors representing the iterations of the algorithm. It iteratively calculates the remainders and updates the coefficients \( x \) and \( y \) until the remainder becomes zero. The `displayIterations` function prints out a table showing the iterations of the algorithm, including the values of \( a \), \( b \), \( x_0 \), \( y_0 \), \( x_1 \), \( y_1 \), and the quotient \( q \) for each iteration. In the `main` function, it prompts the user to enter two numbers \( a \) and \( b \), calls the `extendedEuclideanAlgorithm` function to compute the iterations, and then displays the iterations using the `displayIterations` function.

5. **MultiplicativeInverse.cpp**:
   - This C++ program computes the multiplicative inverse of a given number modulo another number using the Extended Euclidean Algorithm. It first defines a function `extendedEuclideanAlgorithm` which computes the iterations of the Extended Euclidean Algorithm, similar to the previous example. Then, it defines a function `multiplicativeInverse` which utilizes the Extended Euclidean Algorithm to find the multiplicative inverse of a given number modulo another number. In the `main` function, it prompts the user to enter a number and a modulo, computes the multiplicative inverse using the `multiplicativeInverse` function, and then prints the result.

6. **PlayFair.cpp**:
   - This C++ program implements the Playfair Cipher encryption and decryption. The Playfair Cipher is a substitution cipher that uses a 5x5 matrix of letters generated from a given key. The `PlayfairCipher` class contains methods to generate the matrix, find the position of a letter in the matrix, encrypt a pair of letters, and decrypt a pair of letters. In the `main` function, it prompts the user to enter a key, then creates a `PlayfairCipher` object using that key. It then prompts the user to enter plaintext, encrypts it using the `encrypt` method, and prints the encrypted text. It then decrypts the encrypted text using the `decrypt` method and prints the decrypted text. Overall, this program allows for the encryption and decryption of text using the Playfair Cipher.

7. **RailFence.cpp**:
   - This C++ program implements the Rail Fence Cipher for encryption and decryption. The `railFenceEncrypt` function takes the original message and the key (number of rails) as input and returns the encrypted message. It constructs a rail fence structure using a vector of vectors, filling in the rails with characters from the original message. The `railFenceDecrypt` function takes the encrypted message and the key as input and returns the decrypted message. It first fills the rail fence structure with placeholders to mark the rail positions, then fills in the structure with the encrypted message characters. Finally, it reads back the message from the rail fence structure. In the `main` function, it prompts the user to enter the message and the key, encrypts the message using the `railFenceEncrypt` function, prints the encrypted message, decrypts the encrypted message using the `railFenceDecrypt` function, and prints the decrypted message. This program allows for the encryption and decryption of messages using the Rail Fence Cipher.

8. **ShiftCipher.cpp**:
   - This C++ program implements the Caesar Cipher for encryption and decryption. The `encrypt` function takes the plaintext and the shift (key) as input and returns the encrypted ciphertext. It shifts each alphabetical character in the plaintext by the given shift value while preserving the case (uppercase or lowercase). The `decrypt` function takes the ciphertext and the shift as input and returns the decrypted plaintext. It calls the `encrypt` function with a shift value equal to 26 minus the original shift value, effectively reversing the encryption. In the `main` function, the user is prompted to input the plaintext and the shift value. Then, the program encrypts the plaintext using the `encrypt` function, prints the encrypted ciphertext, decrypts the ciphertext using the `decrypt` function, and prints the decrypted plaintext. This program allows for the encryption and decryption of messages using the Caesar Cipher with a specified shift value.

9. **VigenereCipher.cpp**:
   - This C++ program implements the Vigenère Cipher for encryption and decryption. The `vigenereEncrypt` function takes the plaintext and the key as input and returns the encrypted ciphertext. It iterates through each character of the plaintext and shifts it by the corresponding character in the key (repeating the key if necessary) while preserving the case and non-alphabetic characters. The `vigenereDecrypt` function takes the ciphertext and the key as input and returns the decrypted plaintext. It performs the inverse operation of the encryption, shifting each character of the ciphertext back by the corresponding character in the key. In the `main` function, the user is prompted to input the message and the key. Then

## Installation
1. Clone the repository:
    ```bash
    git clone https://github.com/samyam81/CryptoGraphy-Lab.git
    ```
2. Run the code that you want to run.

## Author
This project was created by [Samyam](https://github.com/samyam81).
