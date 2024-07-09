#include <iostream>
#include <cmath>

using namespace std;

int powerMod(int base, int exp, int mod) {
    if (mod == 1) return 0;
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) 
            result = (result * base) % mod;
        exp = exp >> 1; 
        base = (base * base) % mod; 
    }
    return result;
}

void diffieHellman(int p, int g) {
    int a;
    cout << "Enter Alice's private key (a): ";
    cin >> a;

    int b;
    cout << "Enter Bob's private key (b): ";
    cin >> b;

    int A = powerMod(g, a, p); 
    int B = powerMod(g, b, p); 

    cout << "Alice sends public key A to Bob: " << A << endl;
    cout << "Bob sends public key B to Alice: " << B << endl;

    int secret1 = powerMod(B, a, p); 
    int secret2 = powerMod(A, b, p); 

    if (secret1 == secret2) {
        cout << "Shared secret (Key) computed by both Alice and Bob: " << secret1 << endl;
    } else {
        cout << "Error in computing shared secret!" << endl;
    }
}

int main() {
    int p, g;

    cout << "Enter a prime number (modulus p): ";
    cin >> p;

    cout << "Enter a base (primitive root) g: ";
    cin >> g;

    diffieHellman(p, g);

    cout<<"Name: Samyam Subedi \nRoll No: 86 \nSection: C"<<endl;
    return 0;
}
