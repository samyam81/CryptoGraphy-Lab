#include <iostream>
#include <string>
#include <vector>

using namespace std;

string railFenceEncrypt(const string& original, int key) {
    string encrypted;
    int i, j = 0, direction = 1;
    vector<vector<char>> rail(key, vector<char>(original.size(), ' '));

    for (i = 0; i < original.size(); i++) {
        rail[j][i] = original[i];
        if (j == key - 1) {
            direction = -1; // Change direction when reaching bottom rail
        } else if (j == 0) {
            direction = 1; // Change direction when reaching top rail
        }
        j += direction;
    }

    // Construct encrypted message from rail
    for (i = 0; i < key; i++) {
        for (j = 0; j < original.size(); j++) {
            if (rail[i][j] != ' ') {
                encrypted += rail[i][j];
            }
        }
    }

    return encrypted;
}

string railFenceDecrypt(const string& encrypted, int key) {
    string decrypted;
    int i, j = 0, direction = 1;
    vector<vector<char>> rail(key, vector<char>(encrypted.size(), ' '));

    // Fill the rail fence structure with placeholders
    for (i = 0; i < encrypted.size(); i++) {
        rail[j][i] = '*'; // Placeholder to mark rail positions
        if (j == key - 1) {
            direction = -1; // Change direction when reaching bottom rail
        } else if (j == 0) {
            direction = 1; // Change direction when reaching top rail
        }
        j += direction;
    }

    // Fill the rail fence with the encrypted message
    int index = 0;
    for (i = 0; i < key; i++) {
        for (j = 0; j < encrypted.size(); j++) {
            if (rail[i][j] == '*') {
                rail[i][j] = encrypted[index++];
            }
        }
    }

    // Read the message back from the rail fence
    j = 0;
    direction = 1;
    for (i = 0; i < encrypted.size(); i++) {
        decrypted += rail[j][i];
        if (j == key - 1) {
            direction = -1; // Change direction when reaching bottom rail
        } else if (j == 0) {
            direction = 1; // Change direction when reaching top rail
        }
        j += direction;
    }

    return decrypted;
}
int main() {
    string message;
    int key;

    // Input message and key
    cout << "Enter the message: ";
    getline(cin, message); // Allowing spaces in the message
    cout << "Enter the key: ";
    cin >> key;

    // Encryption
    string encrypted = railFenceEncrypt(message, key);
    cout << "Encrypted message: " << encrypted << endl;

    // Decryption
    string decrypted = railFenceDecrypt(encrypted, key);
    cout << "Decrypted message: " << decrypted << endl;

    return 0;
}
