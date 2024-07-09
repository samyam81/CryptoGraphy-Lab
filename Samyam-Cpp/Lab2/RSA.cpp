#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

long long modularExponentiation(long long base, unsigned int exp, int mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp & 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

void generateKeys(int& e, int& d, int& n) {
    int p, q;
    cout << "Enter two prime numbers (p and q): ";
    cin >> p >> q;

    if (!isPrime(p) || !isPrime(q)) {
        cerr << "Error: Both numbers must be prime." << endl;
        exit(1);
    }

    n = p * q;
    int phi = (p - 1) * (q - 1);

    cout << "Enter public key (e): ";
    cin >> e;

    if (e <= 1 || e >= phi || gcd(e, phi) != 1) {
        cerr << "Error: Public key 'e' must be between 1 and " << phi << " and gcd(e, phi) must be 1." << endl;
        exit(1);
    }

    d = 0;
    for (int k = 1; k <= phi; ++k) {
        if ((k * phi + 1) % e == 0) {
            d = (k * phi + 1) / e;
            break;
        }
    }

    cout << "Public key (e, n): (" << e << ", " << n << ")" << endl;
    cout << "Private key (d, n): (" << d << ", " << n << ")" << endl;
}

vector<int> encrypt(const string& message, int e, int n) {
    vector<int> encryptedMessage;
    for (char c : message) {
        int m = int(c);
        int cipher = modularExponentiation(m, e, n);
        encryptedMessage.push_back(cipher);
    }
    return encryptedMessage;
}

string decrypt(const vector<int>& encryptedMessage, int d, int n) {
    string decryptedMessage;
    for (int cipher : encryptedMessage) {
        int m = modularExponentiation(cipher, d, n);
        decryptedMessage += char(m);
    }
    return decryptedMessage;
}

int main() {
    int e, d, n;
    generateKeys(e, d, n);
    string message;
    cout << "Enter message to encrypt: ";
    cin.ignore();
    getline(cin, message);

    vector<int> encryptedMessage = encrypt(message, e, n);
    cout << "Encrypted message: ";
    for (int cipher : encryptedMessage)
        cout << cipher << " ";
    cout << endl;

    string decryptedMessage = decrypt(encryptedMessage, d, n);
    cout << "Decrypted message: " << decryptedMessage << endl;

    cout<<"Name: Samyam Subedi \nRoll No: 86 \nSection: C"<<endl;
    return 0;
}
