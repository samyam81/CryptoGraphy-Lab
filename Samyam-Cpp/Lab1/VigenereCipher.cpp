#include <iostream>
#include <string>

using namespace std;

string vigenereEncrypt(const string& plaintext, const string& key) {
    string ciphertext = "";
    for (size_t i = 0; i < plaintext.size(); ++i) {
        char c = plaintext[i];
        char k = key[i % key.size()]; // Repeats key if shorter than plaintext
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            ciphertext += (char)(((c - base) + (k - 'A')) % 26 + base);
        } else {
            ciphertext += c; // Non-alphabetic characters remain unchanged
        }
    }
    return ciphertext;
}

string vigenereDecrypt(const string& ciphertext, const string& key) {
    string plaintext = "";
    for (size_t i = 0; i < ciphertext.size(); ++i) {
        char c = ciphertext[i];
        char k = key[i % key.size()]; // Repeats key if shorter than ciphertext
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            plaintext += (char)(((c - base + 26) - (k - 'A')) % 26 + base);
        } else {
            plaintext += c; // Non-alphabetic characters remain unchanged
        }
    }
    return plaintext;
}

int main() {
    string message;
    string key;

    // Input message and key
    cout << "Enter the message: ";
    getline(cin, message); // Allowing spaces in the message
    cout << "Enter the key: ";
    cin >> key;

    // Encryption
    string encrypted = vigenereEncrypt(message, key);
    cout << "Encrypted message: " << encrypted << endl;

    // Decryption
    string decrypted = vigenereDecrypt(encrypted, key);
    cout << "Decrypted message: " << decrypted << endl;

    return 0;
}