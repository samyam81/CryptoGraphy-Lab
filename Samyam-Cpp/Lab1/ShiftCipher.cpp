#include <iostream>
#include <string>

using namespace std;

string encrypt(string plaintext, int shift) {
    string ciphertext = "";

    for (char& c : plaintext) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            ciphertext += (c - base + shift) % 26 + base;
        } else {
            ciphertext += c;
        }
    }

    return ciphertext;
}

string decrypt(string ciphertext, int shift) {
    return encrypt(ciphertext, 26 - shift);
}

int main() {
    string plaintext;
    int shift = 3;

    cout<<"Give plainText as input"<<endl;
    cin>>plaintext;

    cout << "Original: " << plaintext << endl;
    string encrypted = encrypt(plaintext, shift);

    cout<<"The key is "<<shift<<endl;
    cout << "Encrypted: " << encrypted << endl;
    string decrypted = decrypt(encrypted, shift);
    cout << "Decrypted: " << decrypted << endl;

    return 0;
}
