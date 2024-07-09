#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class PlayfairCipher {
private:
    string key;
    char matrix[5][5];

    void generateMatrix() {

        int k = 0;
        bool used[26] = {false};

        // Populate the matrix with the key
        for (char c : key) {
            if (!isalpha(c))
                continue;
            char uc = toupper(c);
            if (!used[uc - 'A'] && uc != 'J') { // Ignore duplicates and 'J'
                matrix[k / 5][k % 5] = uc;
                used[uc - 'A'] = true;
                k++;
            }
        }

        // Fill the remaining matrix with the alphabet (excluding 'J')
        for (char c = 'A'; c <= 'Z'; c++) {
            if (c == 'J') // Skip 'J'
                continue;
            if (!used[c - 'A']) {
                matrix[k / 5][k % 5] = c;
                k++;
            }
        }
    }

    pair<int, int> findPosition(char letter) {
        for (int i = 0; i < 5; i++) 
            for (int j = 0; j < 5; j++) 
                if (matrix[i][j] == letter)
                    return make_pair(i, j);
        return make_pair(-1, -1);
    }

    string encryptPair(char a, char b) {

        if (a == b)
            b = 'X';

        auto posA = findPosition(a);
        auto posB = findPosition(b);

        if (posA.first == posB.first) 
            return string(1, matrix[posA.first][(posA.second + 1) % 5]) +
                   string(1, matrix[posB.first][(posB.second + 1) % 5]);
        
        else if (posA.second == posB.second) 
            return string(1, matrix[(posA.first + 1) % 5][posA.second]) +
                   string(1, matrix[(posB.first + 1) % 5][posB.second]);
        
        else 
            return string(1, matrix[posA.first][posB.second]) +
                   string(1, matrix[posB.first][posA.second]);
        
    }

    string decryptPair(char a, char b) {

        auto posA = findPosition(a);
        auto posB = findPosition(b);

        if (posA.first == posB.first) 
            return string(1, matrix[posA.first][(posA.second + 4) % 5]) +
                   string(1, matrix[posB.first][(posB.second + 4) % 5]);
        else if (posA.second == posB.second) 
            return string(1, matrix[(posA.first + 4) % 5][posA.second]) +
                   string(1, matrix[(posB.first + 4) % 5][posB.second]);
        
        else 
            return string(1, matrix[posA.first][posB.second]) +
                   string(1, matrix[posB.first][posA.second]);
        
    }

public:

    PlayfairCipher(string key) : key(key) {
        generateMatrix();
    }

    string encrypt(string plaintext) {
        string encryptedText;

        plaintext.erase(remove_if(plaintext.begin(), plaintext.end(), [](char c) { return !isalpha(c); }), plaintext.end());

        if (plaintext.length() % 2 != 0)
            plaintext += 'X';

        for (size_t i = 0; i < plaintext.length(); i += 2) {
            char a = toupper(plaintext[i]);
            char b = toupper(plaintext[i + 1]);
            encryptedText += encryptPair(a, b);
        }

        return encryptedText;
    }

    string decrypt(string ciphertext) {
        string decryptedText;

        for (size_t i = 0; i < ciphertext.length(); i += 2) {
            char a = toupper(ciphertext[i]);
            char b = toupper(ciphertext[i + 1]);
            decryptedText += decryptPair(a, b);
        }

        return decryptedText;
    }

    void printMatrix() {
        cout << "Playfair Cipher Matrix:" << endl;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    string key;
    cout << "Enter the key: ";
    cin >> key;
    
    PlayfairCipher cipher(key);
    cipher.printMatrix(); // Print the key matrix
    
    string plaintext;
    cout << "Enter the plaintext: ";
    cin >> plaintext;
    
    string encrypted = cipher.encrypt(plaintext);
    cout << "Encrypted: " << encrypted << endl;
    
    string decrypted = cipher.decrypt(encrypted);
    cout << "Decrypted: " << decrypted << endl;

    cout << "Name: Samyam Subedi \nRoll No: 86 \nSection: C" << endl;
    
    return 0;
}
