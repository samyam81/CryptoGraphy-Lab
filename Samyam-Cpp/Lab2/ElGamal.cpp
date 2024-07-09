#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

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

long long modExp(long long base, unsigned int exp, int mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

int generatePrime(int min, int max) {
    int p = rand() % (max - min + 1) + min;
    while (!isPrime(p)) {
        p = rand() % (max - min + 1) + min;
    }
    return p;
}

void generateKeys(int& privateKey, int& publicKey, int& primeNum) {
    srand(time(0));
    int g = 2; 
    primeNum = generatePrime(100, 1000); 
    privateKey = rand() % (primeNum - 2) + 1; 
    publicKey = modExp(g, privateKey, primeNum); 
}

void encrypt(int& c1, int& c2, int m, int publicKey, int primeNum) {
    srand(time(0));
    int g = 2; 
    int k = rand() % (primeNum - 2) + 1; 
    c1 = modExp(g, k, primeNum); 
    c2 = (modExp(publicKey, k, primeNum) * m) % primeNum; 
}

int decrypt(int c1, int c2, int privateKey, int primeNum) {
    int temp = modExp(c1, privateKey, primeNum);
    int inverse = 1;
    while ((temp * inverse) % primeNum != 1) {
        inverse++;
    }
    return (c2 * inverse) % primeNum;
}

int main() {
    int privateKeyA, publicKeyA, primeNum;
    generateKeys(privateKeyA, publicKeyA, primeNum);

    cout << "Generated keys for Alice:" << endl;
    cout << "Private Key (a): " << privateKeyA << endl;
    cout << "Public Key (A, primeNum): (" << publicKeyA << ", " << primeNum << ")" << endl;

    int message;
    cout << "Enter a message (integer): ";
    cin >> message;

    int c1, c2;
    encrypt(c1, c2, message, publicKeyA, primeNum);
    cout << "Encrypted Message (c1, c2): (" << c1 << ", " << c2 << ")" << endl;

    int decryptedMessage = decrypt(c1, c2, privateKeyA, primeNum);
    cout << "Decrypted Message: " << decryptedMessage << endl;

    cout<<"Name: Samyam Subedi \nRoll No: 86 \nSection: C"<<endl;
    return 0;
}
