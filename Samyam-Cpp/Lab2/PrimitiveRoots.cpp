#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int totient(int n) {
    int result = n;
    for (int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

bool isPrimitiveRoot(int g, int n) {
    int phi = totient(n);
    vector<int> powers(phi);
    int x = 1;
    for (int i = 0; i < phi; ++i) {
        powers[i] = x;
        x = (x * g) % n;
    }
    if (powers[0] != 1 || powers[phi - 1] != phi)
        return false;

    return true;
}

void findPrimitiveRoots(int n) {
    vector<int> primitiveRoots;
    for (int g = 2; g < n; ++g) {
        if (isPrimitiveRoot(g, n)) {
            primitiveRoots.push_back(g);
        }
    }
    if (primitiveRoots.empty()) {
        cout << "No primitive roots found for " << n << endl;
    } else {
        cout << "Primitive roots of " << n << ": ";
        for (int root : primitiveRoots) {
            cout << root << " ";
        }
        cout << endl;
    }
}

int main() {
    int number;
    cout << "Enter a positive integer to find its primitive roots: ";
    cin >> number;
    
    if (number <= 1) {
        cerr << "Error: Input must be a positive integer greater than 1." << endl;
        return 1;
    }
    
    findPrimitiveRoots(number);

    cout << "Name: Samyam Subedi \nRoll No: 86 \nSection: C" << endl;
    return 0;
}
